#include<bits/stdc++.h>
using namespace std;
int ans[5];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int a1=c1[0]*10+c1[1];
    int a2=c2[0]*10+c2[1];
    int b1=s1[0]*10+s1[1];
    int b2=s2[0]*10+s2[1];
    int x1=s1[2];
    int x2=s2[2];
    if(a1==a2)
    {
        ans[0]=1;
    }
    if(ans[0]==1&&b1==b2)
    {
        ans[1]=1;
    }
    if(ans[1]==1&&((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
    &&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))
    ||((s1[2]=='D'&&s1[2]=='F')||(s2[2]=='D'&&s2[2]=='F')))
    {
        ans[2]=1;
    }
    if(ans[2]==1&&((x1-x2==1)||x2-x1==1))
    {
        ans[3]=1;
    }
    for(int i=0;i<=3;i++)
    {
        cout<<ans[i];
    }
    return 0;
}