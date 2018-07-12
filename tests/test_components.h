//
// Components unit tests
//
// ICRAR - International Centre for Radio Astronomy Research
// (c) UWA - The University of Western Australia, 2018
// Copyright by UWA (in the framework of the ICRAR)
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
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
//

#include <cxxtest/TestSuite.h>

#include "components.h"

using namespace shark;

class TestOptions : public CxxTest::TestSuite {

public:

	void _init_baryons(Baryon &b1, Baryon &b2) {
		b1.mass = 1.;
		b1.mass_metals = 2.;
		b2.mass = 3.;
		b2.mass_metals = 4.;
	}

	void _assert_addition(const Baryon &b) {
		TS_ASSERT_DELTA(b.mass, 4., 1e-8);
		TS_ASSERT_DELTA(b.mass_metals, 6., 1e-8);
	}

	void test_baryons_compound_addition() {
		Baryon b1, b2;
		_init_baryons(b1, b2);
		b2 += b1;
		_assert_addition(b2);
	}

	void test_baryons_addition() {
		Baryon b1, b2;
		_init_baryons(b1, b2);
		Baryon b3 = b2 + b1;
		_assert_addition(b3);
	}

};