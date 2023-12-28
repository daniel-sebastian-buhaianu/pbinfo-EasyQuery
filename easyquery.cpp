#include <fstream>
using namespace std;
int main()
{
  ifstream f("easyquery.in");
  int n; f >> n;
  int* a = new int[n];
  for (int i = 0; i < n; i++) f >> a[i];
  int* b = new int[n+1];
  b[0] = a[0], b[n] = 0;
  for (int i = 1; i < n; i++) b[i] = a[i] - a[i-1];
  int T; f >> T;
  for (int i = 0; i < T; i++)
  {
    int t, x, y, p; f >> t >> x >> y >> p;
    x--, y--; // retin indicii de la 0
    if (t == 2) p *= -1;
    b[x] += p, b[y+1] -= p;
  }
  f.close();
  a[0] = b[0];
  for (int i = 1; i < n; i++) a[i] = a[i-1] + b[i];
  ofstream g("easyquery.out");
  for (int i = 0; i < n; i++) g << a[i] << ' ';
  g.close();
  return 0;
}

