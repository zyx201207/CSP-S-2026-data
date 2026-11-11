#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    bool ans1=1,ans2=1,ans3=0;
    for(int i=0;i<=1;i++)
    {
        if(c1[i]!=c2[i]) ans1=0;
    }
    cout<<ans1;
    if(!ans1) ans2=0;
    for(int i=0;i<=1;i++)
    {
        if(s1[i]!=s2[i]) ans2=0;
    }
    cout<<ans2;
    if(ans1&&ans2&&((s1[2]-'A'<=2&&s2[2]-'A'<=2)||((s1[2]=='F'&&s2[2]=='D')||(s2[2]=='D'&&s2[2]=='F')))) ans3=1;
    cout<<ans3;
    bool ans4=0;
    if(ans1&&ans2&&ans3)
    {
        int a=s1[2]-'A',b=s2[2]-'A';
        if(abs(a-b)==1) ans4=1;
    }
    cout<<ans4<<endl;
    return 0;
}
