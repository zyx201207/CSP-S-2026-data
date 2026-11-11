#include<bits/stdc++.h>
using namespace std;
int a[211111];
vector<string> o,v;
bool f[211111];
string sol(int x)
{
    string s="";
    while(x)
    {
        s+=x%2+'0';
        x/=2;
    }
    reverse(s.begin(),s.end());
    return s;
}
int sol2(string x)
{
    int ans=0,t=1;
    for(int i=x.size()-1;i>=0;i--)
    {
        ans+=(x[i]-'0')*t;
        t*=2;
    }
    return ans;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,mx=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        string t=sol(a[i]);
        mx=max(mx,int(t.size()));
        o.push_back(t);
    }
    for(int i=0;i<n;i++)
    {
        string t=o[i];
        for(int j=0;j<mx-o[i].size();j++)
            t='0'+t;
        v.push_back(t);
    }
    string ans="";
    for(int i=0;i<mx;i++)
    {
        int an=1;
        int t=0;
        for(int j=0;j<n;j++)
        {
            if(!f[j] && v[j][i]=='1')
            {
                t++;
            }   
        }
        if(t<m)
            an=0;
        if(an==1)
        {
            for(int j=0;j<n;j++)
                if(v[j][i]=='0')
                    f[j]=1;
        }
        ans+=an+'0';
    }
    cout<<sol2(ans);
    return 0;
}