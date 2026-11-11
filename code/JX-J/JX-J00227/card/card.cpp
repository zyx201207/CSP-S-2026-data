#include <bits/stdc++.h>;
using namespace std;
#define ll long long
const int N=5e5+10;
const int M=3e5+10;
int n,m,cnt=1;
int cn[N],cm[M];
void solve()
{
    int ct[N];
    int x=n,s=1;
    int vis[N][2];
    for(int i=cnt;i<=n;i++)
    {
        for(int j=1;j<s;j++)
        {
            if(cn[i]==ct[j])
            {
                s=j;
                break;
            }
        }
        ct[s]=cn[i];
        s++;
    }
    for(int i=1;i<s;i++) cm[ct[i]]++;
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>cn[i];
    }
    int x=n;
    while(x--)
    {
        solve();
        cnt++;
    }
    for(int i=1;i<=m;i++)
    {
        cout<<cm[i]<<" ";
    }
    return 0;
}
