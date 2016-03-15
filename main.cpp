/*
most_frequent_element_from_array -- this program finds the most frequent element
in the array and it's frequency
Copyright (C) <2016>  <Elena Filenko>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/



#include <iostream>>
#include <algorithm>
#include <vector>

using namespace std;

///
/// \brief most_frequent_element_from_integer_array
/// \param vec -- unsorted vector of all elements
/// \param size -- number of elements in the vector
/// \param res -- two integers array, res[ 0 ] -- element frequency, res[ 1] -- element
///

void most_frequent_element_from_integer_array( vector<int>& vec, int size, int* res )
{
    sort( vec.begin(), vec.begin() + size );

    int i = 0;
    int j = 0;
    int cur = vec[0];

    while( i < size )
    {
        j = i + 1;
        while( ( vec[j] == cur ) && (j < size) )
            ++j;

        if( res[ 0 ] < j - i )
        {
            res[ 0 ] = j - i;
            res[ 1 ] = cur;
        }

        cur = vec[ j ];
        i = j;
    }
}

///
/// \brief main
/// \param argc -- number of arguments
/// \param argv -- arguments array
/// \return
///
int main(int argc, char *argv[])
{
    // TEST 1
    {
        int array[] = { 21, -12, 21, 1, 34, 15, 0, 0, 0, 0, 3 };
        int res[ 2 ] = { -10000000 };
        vector<int> vec( array, array + 11 );

        most_frequent_element_from_integer_array( vec, 11, res );

        cout <<  *res << "  " << *(res + 1) << endl << endl;
    }

    // TEST 2
    {
        int array[] = { 21, 21, 21, 21, 21, 21 };
        int res[ 2 ] = { -10000000 };
        vector<int> vec( array, array + 6 );

        most_frequent_element_from_integer_array( vec, 6, res );

        cout <<  *res << "  " << *(res + 1) << endl << endl;
    }

    // TEST 3
    {
        int array[] = { -3, -8, -9, 0, -8 };
        int res[ 2 ] = { -10000000 };
        vector<int> vec( array, array + 5 );

        most_frequent_element_from_integer_array( vec, 5, res );

        cout <<  *res << "  " << *(res + 1) << endl << endl;
    }

    return 0;
}
