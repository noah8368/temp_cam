#ifndef TEMP_CAM_H_
#define TEMP_CAM_H_

#include "i3system_TE.h"

// Returns data from a connected TE camera, and throw an error if one isn't
// found.
// WARNING: If multiple cameras are connected, this function returns information
// about only one of them.
int GetCamId();

// Take a photo, and save the image heat data to a CSV file. This function
// assumes params are for a valid, connected TE Cam.
void TakePhoto(int model, int id);

// Save temperature (in C) at each point in a captured image to a file.
void SaveImgData(i3::TE_B *cam_handle);

#endif // TEMP_CAM_H_
