/*
Copyright (c) 2015 C. D. Tharindu Mathew
http://mackiemathew.wordpress.com

This project is free software: you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License
along with this program. If not, see <http://www.gnu.org/licenses/agpl-3.0.html>.
*/
#include "stdafx.h"
#include "procutils.h"
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "stb_image_write.h"

void ProcUtils::loadImg(const std::string& fileName, unsigned char*& buffer, int* x, int* y, int* channels, const int reqd_channels) {
	buffer = stbi_load(fileName.c_str(), x, y, channels, reqd_channels);
	if (!buffer) {
		std::cout << "Image loading failed: " << stbi_failure_reason() << std::endl;
	}
}

void ProcUtils::freeImg(unsigned char* buffer) {
	stbi_image_free(buffer);
}


void ProcUtils::writeImg(const std::string& fileName, const unsigned char* buffer, const int width, const int height, int components) {
	stbi_write_png(fileName.c_str(), width, height, components, buffer, 0);
}