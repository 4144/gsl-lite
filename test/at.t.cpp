//
// gsl-lite is based on GSL: Guidelines Support Library,
// https://github.com/microsoft/gsl
//
// Copyright (c) 2015 Martin Moene
// Copyright (c) 2015 Microsoft Corporation. All rights reserved. 
// 
// This code is licensed under the MIT License (MIT). 
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN 
// THE SOFTWARE. 

#include "gsl-lite.t.h"

CASE( "at(): Terminates access to non-existing C-array elements" )
{
    int a[] = { 1, 2, 3, 4 };

    EXPECT_THROWS( at(a, 4) );
}

CASE( "at(): Terminates access to non-existing std::array elements (C++11)" )
{
#if gsl_HAVE_ARRAY
    std::array<int, 4> a = {{ 1, 2, 3, 4 }};

    EXPECT_THROWS( at(a, 4) );
#else
    EXPECT( !!"std::array<> is not available (no C++11)" );
#endif
}

CASE( "at(): Terminates access to non-existing std::vector elements" )
{
    std::vector<int> a; // = { 1, 2, 3, 4 };

    for ( int i = 0; i < 4; ++i )
    {
        a.push_back( i + 1 );
    }

    EXPECT_THROWS( at(a, 4) );
}

CASE( "at(): Terminates access to non-existing std::initializer_list elements" )
{
    std::initializer_list<int> a = { 1, 2, 3, 4 };

    EXPECT_THROWS( at(a, 4) );
}

CASE( "at(): Terminates access to non-existing gsl::span elements" )
{
    int arr[] = { 1, 2, 3, 4 };
    span<int> a( arr );

    EXPECT_THROWS( at(a, 4) );
}

CASE( "at(): Allows access to existing C-array elements" )
{
    int a[] = { 1, 2, 3, 4 };

    for ( int i = 0; i < 4; ++i )
    {
        EXPECT( at(a, i) ==  i + 1 );
    }
}

CASE( "at(): Allows access to existing std::array elements (C++11)" )
{
#if gsl_HAVE_ARRAY
    std::array<int, 4> a = {{ 1, 2, 3, 4 }};

    for ( int i = 0; i < 4; ++i )
    {
        EXPECT( at(a, i) == i + 1 );
    }
#else
    EXPECT( !!"std::array<> is not available (no C++11)" );
#endif
}

CASE( "at(): Allows access to existing std::vector elements" )
{
    std::vector<int> a; // = { 1, 2, 3, 4 };

    for ( int i = 0; i < 4; ++i )
    {
        a.push_back( i + 1 );
        EXPECT( at(a, i) == i + 1 );
    }
}

CASE( "at(): Allows access to std::initializer_list elements (C++11)" )
{
#if gsl_HAVE_INITIALIZER_LIST
    std::initializer_list<int> a = { 1, 2, 3, 4 };

    for ( int i = 0; i < 4; ++i )
    {
        EXPECT( at(a, i) == i + 1 );
    }
#else
    EXPECT( !!"std::initializer_list<> is not available (no C++11)" );
#endif
}

CASE( "at(): Allows access to gsl::span elements" )
{
    int arr[] = { 1, 2, 3, 4 };
    span<int> a( arr );

    for ( int i = 0; i < 4; ++i )
    {
        EXPECT( at(a, i) == i + 1 );
    }
}

// end of file
