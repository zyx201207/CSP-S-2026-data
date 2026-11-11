#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200005];
vector<vector<ll>> x(18);
int pow2[18]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072};
vector<vector<ll>> x2(18);
ll vis[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        int a2=a[i];
        for(int j=17;j>=0;j--)
        {
            if(a2>=pow2[j])
            {
                x[j].push_back(i);
                a2-=pow2[j];
            }
        }
    }
    ll ans=0,cnt=0;
    int flag=0;
    for(int i=17;i>=0;i--)
    {
        int len=x[i].size();
        if(x[i].size()>=m)
        {

            for(int j=0;j<x[i].size();j++)
            {
                if(vis[x[i][j]]!=cnt)
                {
                    len--;
                }
            }
            if(len<m) continue;
            for(int j=0;j<x[i].size();j++) vis[x[i][j]]++;
            cnt++;
            ans+=pow2[i];
        }
    }
    cout<<ans;
    return 0;
}
