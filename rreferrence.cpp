#include <iostream>
#include <string>
#include <vector>

void print(const std::vector<std::string>& vec) {
    std::cout << "left: ";
    for(auto& item : vec) {
        std::cout << item << " ";
    } std::cout << std::endl;
}
void print(std::vector<std::string>&& vec) {
    std::cout << "right: ";
    for(auto& item : vec) {
        std::cout << item << " ";
    } std::cout << std::endl;
}

int main() {
    std::vector<std::string> v { "Hello", "World" };
    print(v);
    print({ "Hello", "World" });
    return 0;
}