#include <fstream>
using namespace std;
int main()
{
  ifstream f("easyquery.in");
  int n; f >> n;
  int* a = new int[n];
  int* b = new int[n+1];
  long long s = 0;
  for (int i = 0; i < n; i++)
  {
    f >> a[i];
    b[i] = a[i] - s;
    s += b[i];
  }
  b[n] = 0;
  int T; f >> T;
  for (int i = 0; i < T; i++)
  {
    int t, x, y, p; f >> t >> x >> y >> p;
    x--, y--; // retin indicii de la 0
    if (t == 2) p *= -1;
    b[x] += p, b[y+1] -= p;
  }
  f.close();
  ofstream g("easyquery.out");
  s = 0;
  for (int i = 0; i < n; i++)
  {
    s += b[i];
    g << s << ' ';
  }
  g.close();
  return 0;
}


