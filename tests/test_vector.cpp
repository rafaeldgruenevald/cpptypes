#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include "../src/Lists/Vector.hpp"

using namespace Lists;

//TEST_CASE("Combat: arquivo inexistente retorna FileError", "[combat]") {
//    REQUIRE(c.init("tests/chapters/nao_existe.txt") == ErrorCode::FileError);
//}

TEST_CASE("Initialization and .at() method works") {
    Vector<int> v = {10, 20, 30, 40};
    Vector<char> c;
}

// TEST_CASE(".at() method works") {
//     Vector<int> v = {10, 20, 30, 40};

//     REQUIRE(v.at(0) == 10);
//     REQUIRE(v.at(1) == 20);
//     REQUIRE(v.at(2) == 30);
//     REQUIRE(v.at(3) == 40);
// }

// TEST_CASE("[] operator works") {
//     Vector<int> v = {10, 20, 30, 40};

//     REQUIRE(v[0] == 10);
//     REQUIRE(v[1] == 20);
//     REQUIRE(v[2] == 30);
//     REQUIRE(v[3] == 40);
// }

// TEST_CASE("Assining new value to position works") {
//     Vector<int> v = {10, 20, 30, 40};

//     v[1] = 50;

//     REQUIRE(v[0] == 10);
//     REQUIRE(v[1] == 50);
//     REQUIRE(v[2] == 30);
//     REQUIRE(v[3] == 40);
// }

// TEST_CASE(".size() method works") {
//     Vector<char> v = {'a', 'c', 'f', 'd', 'z'};
//     int s = v.size();

//     REQUIRE(s == 5);
// }

// TEST_CASE(".push_back() method works") {
//     Vector<int> v = {10, 20, 30, 40};

//     v.push_back(5);

//     REQUIRE(v[0] == 10);
//     REQUIRE(v[1] == 50);
//     REQUIRE(v[2] == 30);
//     REQUIRE(v[3] == 40);
//     REQUIRE(v[4] == 5);
// }

// TEST_CASE(".begin() method works") {
//     Vector<int> v = {10, 20, 30, 40};


//     REQUIRE(v.begin() == );
// }

// TEST_CASE(".end() method works") {
//     Vector<int> v = {10, 20, 30, 40};


//     REQUIRE(v.end() == );
// }

// TEST_CASE(".empty() method works") {
//     Vector<int> v = {10, 20, 30, 40};
//     Vector<char> c;

//     REQUIRE(v.empty() == false);
//     REQUIRE(c.empty() == true);
// }

// TEST_CASE(".insert() method works") {
//     Vector<int> v = {10, 20, 30, 40};

//     v.insert(v.begin() + 1, 5);

//     REQUIRE(v[0] == 10);
//     REQUIRE(v[1] == 5);
//     REQUIRE(v[2] == 20);
//     REQUIRE(v[2] == 30);
//     REQUIRE(v[3] == 40);
// }

// TEST_CASE(".pop_back() method works") {
//     Vector<int> v = {10, 20, 30, 40};

//     int initial_size = v.size();

//     v.pop_back();

//     int final_size = v.size();

//     REQUIRE(initial_size == final_size + 1);
// }

// TEST_CASE(".erase() method works") {
//     Vector<int> v = {10, 20, 30, 40};

//     v.erase(3);

//     REQUIRE(v[0] == 10);
//     REQUIRE(v[1] == 20);
//     REQUIRE(v[2] == 40);
// }

// TEST_CASE("Range based loops are working") {
//     Vector<int> v = {10, 20, 30, 40};

//     for (int x : v) {
//         std::cout << x << " ";
//     }

//     // read-only access, avoids copying
//     for (const int &x : v) {
//         std::cout << x << " ";
//     }

//     // able to modify elements of the vector
//     for (int &x : v) {
//         std::cout << x << " ";
//     }

//     REQUIRE()
// }
