#include<bits/stdc++.h>
#define long long

using namespace std;

const int maxn=500005;
int a[maxn];
unsigned long long m,n;

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    int num[maxn];
    memset(num,0,sizeof(num));
    num[1]=a[1];
    for(int i=2;i<=n;i++){
        num[i]=num[i-1]+a[i];
    }
    int ans=-1;
    for(int i=1;i<=n;i++){
        int minm=i*a[i]-num[i];
        if(m>=minm)
            ans=max(ans,i);
    }
    cout<<ans<<'\n';
    return 0;
}
