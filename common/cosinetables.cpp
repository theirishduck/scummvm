/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

// Based on eos' cosine tables

#include "common/cosinetables.h"
#include "common/scummsys.h"

namespace Common {

CosineTable::CosineTable(int bitPrecision) {
	assert((bitPrecision >= 4) && (bitPrecision <= 16));

	_bitPrecision = bitPrecision;

	int m = 1 << _bitPrecision;
	double freq = 2 * M_PI / m;
	_table = new float[m / 2];

	// Table contains cos(2*pi*i/m) for 0<=i<m/4,
	// followed by 3m/4<=i<m
	for (int i = 0; i <= m / 4; i++)
		_table[i] = cos(i * freq);

	for (int i = 1; i < m / 4; i++)
		_table[m / 2 - i] = _table[i];
}

CosineTable::~CosineTable() {
	delete[] _table;
}

} // End of namespace Common
