#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

string c1,s1,c2,s2;
int k[7]={1,1,1,2,0,2};

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    bool ans1=(c1==c2);
    string cr=s1.substr(0,2),cx=s2.substr(0,2);
    bool ans2=((cr==cx)&ans1),ans3=0,ans4=0;
    if(k[s1[2]-'A']==k[s2[2]-'A']) ans3=1;
    ans3=ans3&ans2;
    if(ans3)
    {
        if(abs(s2[2]-s1[2])==1||s2[2]=='D'||s2[2]=='F') ans4=1;
    }
    cout<<ans1<<ans2<<ans3<<ans4;
    return 0;
}
