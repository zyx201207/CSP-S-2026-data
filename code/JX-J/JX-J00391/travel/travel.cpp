#include <bits/stdc++.h>
using namespace std;
int a[3],p[3]; //1R2X
string s[3];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i = 1;i <= 2;i++) cin>>a[i]>>s[i];
    for(int i = 1;i <= 2;i++) p[i] = (s[i][0] - '0') * 10 + (s[i][1] - '0');
    if(a[1] != a[2]) cout<<"0000"<<endl;
    else if(p[1] != p[2]) cout<<"1000"<<endl;
    else if(!((s[1][2] <= 'C' && s[2][2] <= 'C') || (s[1][2] >= 'D' && s[2][2] >= 'D'))) cout<<"1100"<<endl;
    else if(abs(s[1][2] - s[2][2]) != 1) cout<<"1110"<<endl;
    else cout<<"1111"<<endl;
    return 0;
}
