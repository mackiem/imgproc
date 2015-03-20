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

// imgproc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "process.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int _tmain(int argc, _TCHAR* argv[])
{
	std::ofstream file;
	//file.open("yuv-with-unaltered.csv");
	file.open("yuv-with-albedo-compensation.csv");
	std::vector<std::string> colors;
	colors.push_back("blue");
	colors.push_back("cyan");
	colors.push_back("grey");
	colors.push_back("green");
	colors.push_back("black");
	colors.push_back("red");
	colors.push_back("yellow");
	colors.push_back("magenta");
	colors.push_back("white");

	const std::string dir("../buddha-");
	//const std::string suffix("-yuv-original.jpg");
	const std::string suffix("-yuv-albedo-compensated.jpg");
	for (const auto& color : colors) {
		std::string file_name = dir;
		file_name.append(color).append(suffix);
		Process proc(file_name);
		double mean, stddev;
		//int start_x = 1859;
		//int start_y = 60;
		//const int w = 900;
		//const int h = 2469;

        // large rectangle
		//int start_x = 1942;
		//int start_y = 1040;
		//const int w = 720;
		//const int h = 2178;

        // small rectangle, near base
		int start_x = 1821;
		int start_y = 2663;
		const int w = 836;
		const int h = 626;

		proc.avg_RGB(start_x, start_y, w, h, 1, mean, stddev);
		file << color << "," << mean << "," << stddev << ",";
		std::cout << "UU " << color << " mean: " << mean << " std. dev: " << stddev << std::endl;

		proc.avg_RGB(start_x, start_y, w, h, 2, mean, stddev);
		file << mean << "," << stddev << std::endl;
		std::cout << "VV " << color << " mean: " << mean << " std. dev: " << stddev << std::endl;
	}
	file.close();

	//proc.extract_section(800, 800, 2200, 2200);
	return 0;
}

