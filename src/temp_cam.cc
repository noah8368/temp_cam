#include <iostream>
#include <stdexcept>
#include <chrono>
#include <thread>

#include <Windows.h>

#include "temp_cam.h"
#include "i3system_TE.h"

int GetCamId()
{
    const int ERROR_CODE = -1;
    const int SUCCESS_CODE = 1;

    // Scan all connected USB ports for a camera.
    i3::SCANINFO scan_info[MAX_USB_NUM];
    if (i3::ScanTE(scan_info) != SUCCESS_CODE)
    {
        throw std::runtime_error("Unable to find connected camera.");
    }

    // Return ID of the first found connected camera.
    for (int cam_id = 0; cam_id < MAX_USB_NUM; ++cam_id)
    {
        if (scan_info[cam_id].bDevCon == SUCCESS_CODE)
        {
            return cam_id;
        }
    }

    // If no valid cameras were found, throw an error.
    throw std::runtime_error("Unable to find connected camera.");
}

void TakePhoto(int model, int id)
{
    // Open a connection to the TE camera.
    i3::TE_B *cam_handle = i3::OpenTE_B(model, id);
    if (!cam_handle)
    {
        throw std::runtime_error("Unable to communicate with camera.");
    }

    int img_width = cam_handle->GetImageHeight();
    int img_height = cam_handle->GetImageHeight();
    unsigned short *img_data = new unsigned short[img_width * img_height];
    enum ReturnStatus
    {
        NOT_RECV = 0,
        READ_SUCCESS = 1
    };
    const int SLEEP_TIME = 33000;
    int img_capture_status;

    // Collect image data.
    for (;;)
    {
        // TODO: Figure out why the program mysteriously exits here.
        img_capture_status = cam_handle->RecvImage(img_data);
        switch (img_capture_status)
        {
        case READ_SUCCESS:
            // TODO: Write routine to save Temp Data to CVS.
            SaveImgData(cam_handle);
            goto FINISHED_TAKING_IMAGE;
        case NOT_RECV:
            // Continue to wait for image data to be received.
            std::this_thread::sleep_for(std::chrono::microseconds(SLEEP_TIME));
            break;
        default:
            throw std::runtime_error("Problem encountered while taking image.");
        }
    }
FINISHED_TAKING_IMAGE:
    // TODO: Display saved image data.
    std::cout << "SUCCESS!" << std::endl;
    return;
}

void SaveImgData(i3::TE_B *cam_handle)
{
    // TODO: Implement this.
    return;
}