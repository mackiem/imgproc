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
#include "process.h"
#include "procutils.h"
#include <cassert>
#include <algorithm>
#include <numeric>
#include <vector>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

void Process::avg_RGB(int start_x, int start_y, int width, int height, int channel, double& mean, double& stddev) {
	assert(start_x > 0
		&& start_y > 0
		&& width <= width_
		&& height <= height_
		&& channel <= channels_);

    std::vector< int > v;
	for (int y = start_y; y < start_y + height; ++y) {
		for (int x = start_x; x < start_x + width; ++x) {
			for (int k = 0; k < channels_; ++k) {
				if (k == channel) {
			        v.push_back(buffer_[channels_ * (y * width_ + x) + k]);
				}
			}
		}
	}

	//float avg = total / (width * height);
	double sum = std::accumulate(std::begin(v), std::end(v), 0.0);
	mean = sum / v.size();

	double accum = 0.0;
	std::for_each(std::begin(v), std::end(v), [&](const double d) {
		accum += (d - mean) * (d - mean);
	});

	stddev = sqrt(accum / (v.size() - 1));
}

void Process::extract_section(int start_x, int start_y, int width, int height) {
	unsigned char* buf_copy = new unsigned char[width * height * channels_];
	for (int y = start_y; y < start_y + height; ++y) {
		for (int x = start_x; x < start_x + width; ++x) {
			for (int k = 0; k < channels_; ++k) {
			        buf_copy[(channels_ * ((y - start_y) * width + (x - start_x))) +  k] = buffer_[(channels_ * (y * width_ + x)) + k];
			}
		}
	}

	ProcUtils::writeImg("test.png", buf_copy, width, height, channels_);
	delete buf_copy;
}

Process::Process(const std::string& file_name, int reqd_channels) {
	ProcUtils::loadImg(file_name, buffer_, &width_, &height_, &channels_, reqd_channels);
}

Process::~Process()
{
	ProcUtils::freeImg(buffer_);
}
