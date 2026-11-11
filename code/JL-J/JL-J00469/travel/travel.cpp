#include <bits/stdc++.h>
#include <cmath>
using namespace std;
string c1,c2,s1,s2;
string s3,s4;
int a,b,c,d;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //start：
    cin>>c1>>s1>>c2>>s2;
    for(int i=0; i<2; i++)
    {
        s3+=s1[i];
    }
    for(int i=0; i<2; i++)
    {
        s4+=s2[i];
    }
    if(c1 == c2) a = 1;
    if(a == 1 && s3 == s4) b = 1;
    if(b == 1 && (('A' <= s1[2] && s1[2] <= 'C') && ('A' <= s2[2] && s2[2] <= 'C')) || (('D' <= s1[2] && s1[2] <= 'F') && ('D' <= s2[2] && s2[2] <= 'F')))
    {
        c = 1;
    }
    if(c == 1 && abs(s1[2] - s2[2]) == 1)
    {
        d = 1;
    }
    cout<<a<<b<<c<<d;
    return 0;
}
