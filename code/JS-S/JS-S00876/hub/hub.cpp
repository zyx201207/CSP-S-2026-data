#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7;
long long n,m,T;
int a[N];
long long cnt=1;
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>T;
    cin>>n>>m;
    //Dij if(son!=t&&dis[x]+w==dis[son]) cnt[son]++;
    while(T--)cout<<T;
    return 0;
}
