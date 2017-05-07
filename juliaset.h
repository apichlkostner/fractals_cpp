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

#ifndef JULIASET_H
#define JULIASET_H

#include <complex>
#include <vector>

using namespace std;

namespace fractals {

class JuliaSet
{
private:
    double r;
    complex<double> c;
    complex<double> startPhys;
    complex<double> endPhys;
    vector<int> imageSize;

public:
    JuliaSet();
    vector<vector<int>> calc(complex<double> centerPhys, double zoom, vector<int> size);

private:
    int calcPoint(complex<double> jmval, int maxrec);
};

}
#endif // JULIASET_H
