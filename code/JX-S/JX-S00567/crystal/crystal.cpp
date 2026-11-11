#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int n,ans;
long long m,a[MAXN],pre[MAXN];
inline bool check(int x,int r){return a[r]*(r-x+1)-(pre[r]-pre[x-1])<=m;}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
    for(int r=1;r<=n;r++)
    {
        int L=1,R=r;
        while(L<=R)
        {
            int mid=L+((R-L)>>1);
            if(check(mid,r)) R=mid-1;
            else L=mid+1;
        }
        ans=max(ans,r-L+1);
    }
    cout<<ans;
    return 0;
}
//Hello!
//Maybe it can work and I have passed all examples!
//Can I pass the CSP-S 2026 T1? Enjoy the "video" on Luogu!
//My Luogu account's name is "Xiong guan man dao zhen ru tie". Yes, the poem of that person.
//
//And there is something interesting: Letter E and high-speed train.
