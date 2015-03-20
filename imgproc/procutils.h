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

class ProcUtils
{
public:
	static void loadImg(const std::string& fileName, unsigned char*& buffer, int* x, int* y, int* channels, const int reqd_channels);
	static void freeImg(unsigned char* buffer);
	static void writeImg(const std::string& fileName, const unsigned char* buffer, const int width, const int height, int components);
};

