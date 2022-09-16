/* 最大子序列 */
#include <vector>
int maxSubSum(const std::vector<int>& a) {
  int maxSum = 0, thisSum = 0;
  for (int i = 0; i < a.size(); ++i) {
    thisSum += a[i];
    if (maxSum < thisSum) {
      maxSum = thisSum;
    } else if (thisSum < 0) {
      thisSum = 0;
    }
  }
  return maxSum;
}