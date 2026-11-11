#include <bits/stdc++.h>
using namespace std;

bool check1(string s1,string s2)
{
    string t1=s1,t2=s2;
    t1.pop_back();
    t2.pop_back();
    return t1==t2;
}

bool check2(string s1,string s2)
{
    char t1=s1[2],t2=s2[2];
    if (t1<'D'&&t2<'D') return 1;
    if (t1>'C'&&t2>'C') return 1;
    return 0;
}

bool check3(string s1,string s2)
{
    char t1=s1[2],t2=s2[2];
    if (t1=='A'&&t2=='C'||t1=='C'&&t2=='A') return 0;
    return 1;
}

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string r,rr,x,xx;
    cin >> r >> rr >> x >> xx;
    bool ans1=r==x;
    bool ans2=check1(rr,xx)&&ans1;
    bool ans3=check2(rr,xx)&&ans2;
    bool ans4=check3(rr,xx)&&ans3;
    cout << ans1 << ans2 << ans3 << ans4;
    return 0;
}
