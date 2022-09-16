/* 欧几里得算法 */
long long gcd(long long m, long long n) {
  while (n != 0) {
    long long rem = m % n;
    m = n;
    n = rem;
  }
  return m;
}