#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5,inf=LLONG_MAX;
int n,m,k;
int a[N],s[N];
bool check(int x){
    int mm=m,res=inf;
    for(int i=1;i<=n-x+1;i++){
        int r=i+x-1;
        int sum=s[r]-s[i-1];
        res=min(res,a[r]*x-sum);
    }
    return res<=m;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    int l=1,r=n,ans=1;
    while(l<=r){
        int mid=l+r>>1;
        if(check(mid)){
            l=mid+1;
            ans=mid;
        }else r=mid-1;
    }
    cout<<ans;
    return 0;
}

/*
¼ÍÄîAFO-2026-10-31 18:27
		--DreamScope - wjy 
*/
