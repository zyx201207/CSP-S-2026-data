#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,x;
char c;
string s="",s1="";
int ans=0;
signed main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>c;
        for(int i=1;i<=x;i++)
        {
            s+=c;
        }
    }
    string  s1=s;
    reverse(s1.begin(),s1.end());
    int p=s1.size()/2;
    string ss1,ss2;
    if(s.size()%2==0)
    {
        ss1=s1.substr(0,p);
        ss2=s1.substr(p);
    }
    else
    {
        ss1=s1.substr(0,p);
        ss2=s1.substr(p+1);
    }
    for(int i=0;i<ss1.size();i++)
    {
        if(ss1[i]!=ss2[i])ans++;
    }
    cout<<ans;
   return 0;
}
