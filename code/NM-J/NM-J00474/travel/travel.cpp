#include <bits/stdc++.h>
using namespace std;

struct seat
{
    int c;
    int l;
    char s;
};

int ctoi(char c)
{
	return c - '0';
}

bool check(seat a, seat b) // 两张车票对应的座位是否在同一节车厢的同一排,且位于过道的同一侧
{
   if(!(a.l == b.l && a.c == b.c))return false;
    if((a.s <= 'C' && b.s <= 'C')|| (a.s > 'C' && a.s <= 'F' && b.s > 'C' && b.s <= 'F'))return true;
    return false;
}
bool check_(seat a, seat b)
{
    if (!check(a, b)) return false;
    if (abs(a.s - b.s) == 1) return true;
    return false;
}

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    seat R, X;
    // c1, s1, c2, s2
    cin >> R.c;
    string s1, s2;
    cin >> s1;
    cin >> X.c;
    cin >> s2;
    R.l=ctoi(s1[0]) * 10 + ctoi(s1[1]);
    X.l = ctoi(s2[0]) * 10 + ctoi(s2[1]);
    R.s = s1[2];
    X.s = s2[2];
    //ut << s1 << ' ';
  //cout << s2 << ' ';
  //cout << R.c << ' ' << R.l << ' ' <<R.s << ' ' ;

    cout << (X.c == R.c) << (X.l == R.l && X.c == R.c);
 cout<< check(R, X) << check_(R, X);
    return 0;
}
