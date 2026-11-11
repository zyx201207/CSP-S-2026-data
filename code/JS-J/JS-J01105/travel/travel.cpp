#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int a=0,b=0,c=0,d=0,f1,f2;
    for(int i=0;i<c1.size();i++)
        a=a*10+c1[i]-'0';
    for(int i=0;i<c2.size();i++)
        c=c*10+c2[i]-'0';
    for(int i=0;i<s1.size()-1;i++)
        b=b*10+s1[i]-'0';
    for(int i=0;i<s2.size()-1;i++)
        d=d*10+s2[i]-'0';
    f1=s1[2]-'A',f2=s2[2]-'A';
    string ans="0000";
    if(a==c)       ans[0]='1';
    if(a==c&&b==d) ans[1]='1';
    if(a==c&&b==d&&((f1<3&&f2<3)||(f1>2&&f2>2)))
        ans[2]='1';
    if(a==c&&b==d&&((f1<3&&f2<3)||(f1>2&&f2>2))&&abs(f1-f2)==1)
        ans[3]='1';
    cout<<ans;
    return 0;
}
