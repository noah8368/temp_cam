#include <iostream>

#include <Windows.h>
#include "i3system_TE.h"

const int ERROR_CODE = -1;

bool CamConnected()
{
    // Scan all USB interfaces for a connected TE camera.
    i3::SCANINFO scan_info[MAX_USB_NUM];
    const int SCAN_SUCCEEDED = 1;
    if (i3::ScanTE(scan_info) != SCAN_SUCCEEDED)
    {
        perror("Unable to scan USB interfaces.");
        return ERROR_CODE;
    }

    const int CAM_CONNECTED = 1;
    for (auto &usb_cnx : scan_info)
    {
        // Return true as soon as a connected TE camera is found.
        if (usb_cnx.bDevCon == CAM_CONNECTED)
        {
            return true;
        }
    }
    return false;
}
