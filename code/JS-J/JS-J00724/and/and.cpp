#include <bits/stdc++.h>
using namespace std;
vector<int> vec(1);
string bit(int a)
{
    string c="";
    while(a)
    {
        c.push_back(a%2+'0');
        a=a/2;
    }
    return c;
}
bool cmp(int a,int b)
{
    return vec[a]<vec[b];
}
int bfs(int a,int b,int c)
{
    for(int i=c+1;i<vec.size()-b+1&&b;i++)
        a=max(a,bfs(a&vec[i],b-1,i));
    return a;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a,b,c,n,ans=INT_MAX,xxx=INT_MAX;
    string s;
    cin>>a>>n;
    unordered_map<int,pair<int,vector<int> > > mp;
    for(int i=1;i<=a;i++)
    {
        cin>>c;
        vec.push_back(c);
        s=bit(vec[i]);
        b=1<<(s.size()-1);
        for(int j=0;j<s.size();j++)
        {
            if(s[j]=='1')
            {
                mp[b].first++;
                mp[b].second.push_back(i);
            }
        }
    }
    if(n==a-1)
    {
        ans=0;
        for(int i=1;i<=a;i++)
        {
            for(int j=1;j<=a;j++)
            {
                if(i==j)
                    continue;
                xxx=xxx&vec[i];
            }
            ans=max(ans,xxx);
        }
        cout<<ans;
        return 0;
    }
    if(a<=2000)
    {
        ans=0;
        vector<int> aa(n+1);
        for(int i=1;i<=a-n+1;i++)
            ans=max(ans,bfs(vec[i],n-1,i));
        cout<<ans;
        return 0;
    }
    for(int i=1<<30;i>=1;i=i>>1)
    {
        if(mp[i].first==n)
        {
            cout<<1;
            for(int j=0;j<mp[i].second.size();j++)
                ans=ans&vec[mp[i].second[j]],cout<<vec[mp[i].second[j]];
            cout<<ans;
            break;
        }
        else if(mp[i].first>n)
        {
            cout<<i;
            vector<int> x;
            vector<pair<int,int> > p(x.size()-1);
            sort(x.begin(),x.end(),cmp);
            for(int j=1;j<x.size();j++)
            {
                p[j-1].first=vec[0]-vec[0]&vec[j];
                p[j-1].second=i;
            }
            sort(p.begin(),p.end());
            ans=vec[x[0]];
            for(int j=0;j<n-1;j++)
                ans=ans&vec[p[j].second];
            cout<<ans;
            break;
        }
    }
    return 0;
}
