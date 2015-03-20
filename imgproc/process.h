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
#pragma once
#include <string>

class Process
{
private:
	unsigned char* buffer_;
	int width_, height_, channels_;
public:
	Process(const std::string& file_name, int reqd_channels = 3);
	~Process();
	void avg_RGB(int start_x, int start_y, int width, int height, int channel, double& mean, double& stddev);
	void extract_section(int start_x, int start_y, int width, int height);
};

