#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
vector<ll> v1;
vector<ll> de;
ll num[300003]={0};
ll vis[300003]={0};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int tmp;
        cin>>tmp;
        v1.push_back(tmp);
    }
    for(int i=1;i<=n;i++)
    {
        de.clear();
        stack<ll> v;
        for(int j=v1.size()-1;j>=i-1;j--)v.push(v1[j]);
        for(int j=1;j<=m;j++)vis[j]=0;
        while(!v.empty())
        {
            ll tmp=v.top();
            v.pop();
            if(vis[tmp]==0)
            {
                de.push_back(tmp);
                vis[tmp]=de.size();
            }
            else{
                for(ll j=de.size()-1;j>vis[tmp]-1;j--)
                {
                    vis[de[j]]=0;
                    de.pop_back();
                }
            }
        }
        for(ll j=1;j<=m;j++)
        {
            if(vis[j])num[j]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<num[i]<<' ';
    }
    return 0;
}

