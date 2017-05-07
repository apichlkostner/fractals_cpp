// Calculation of julia set
// Copyright (C) 2017  <name of author>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <iostream>
#include "juliaset.h"

namespace fractals {

JuliaSet::JuliaSet()
{

}

vector<vector<int>> JuliaSet::calc(complex<double> centerPhys, double zoom, vector<int> size)
{
    vector<vector<int>> picture(size[0], vector<int>(size[1]));

    c = {0, 1};
    r = (1.0 + sqrt(1.0 + 4.0 * abs(c))) / 2.0;

    double rat = (double)size[1] / (double)size[0];

    complex<double> delta(4.0 * zoom, rat * 4.0 * zoom);
    double delta_x = delta.real() / size[0];
    double delta_y = delta.imag() / size[1];

    double xf = centerPhys.real() - delta.real() / 2;
    double yfr = -(centerPhys.imag() - delta.imag() / 2);


    for (int pixH = 0; pixH < size[0]; pixH++) {
        double yf =yfr;
        for (int pixV = 0; pixV < size[1]; pixV++) {
            picture[pixH][pixV] = calcPoint(complex<double>(xf, yf), 100);
            yf -= delta_y;
        }
        xf += delta_x;
    }

    return picture;
}


int JuliaSet::calcPoint(complex<double> jmval, int maxrec) {
    int i;

    for (i = 0; i < maxrec; i++) {
        jmval = jmval * jmval + c;
        if (abs(jmval) > r)
            break;
    }
    return i;
}

}
