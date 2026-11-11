#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int side1,side2;
    if('A'<=s1[2]&&s1[2]<='C') side1=1;
    else side1=2;
    if('A'<=s2[2]&&s2[2]<='C') side2=1;
    else side2=2;
    bool f1=(c1==c2);
    bool f2=(s1[0]==s2[0]&&s1[1]==s2[1]);
    bool f3=(side1==side2);
    bool f4=(abs(s1[2]-s2[2])==1);
    cout<<f1<<(f1&&f2)<<(f1&&f2&&f3)<<(f1&&f2&&f3&&f4);
    return 0;
}
