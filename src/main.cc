#include <iostream>
#include <stdexcept>

#include <Windows.h>

#include "temp_cam.h"

using namespace std;

int main()
{
    try
    {
        int cam_id = GetCamId();
        TakePhoto(I3_TE_Q1, cam_id);
    }
    catch (runtime_error &e)
    {
        cout << "ERROR" << e.what() << endl;
        exit(EXIT_FAILURE);
    }
}