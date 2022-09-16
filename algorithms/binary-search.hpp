#include <vector>

template <typename Comparable>
int binarySearch(const std::vector<Comparable>& a, const Comparable& b) {
  int low = 0, high = a.size() - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (a[mid] > b) {
      low = mid + 1;
    } else if (a[mid] < b) {
      high = mid - 1;
    } else
      return mid;
  }
  return -1;
}