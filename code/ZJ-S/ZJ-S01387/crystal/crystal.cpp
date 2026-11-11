#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+7;
int n,m,a[N];
int sum[N];
int calc(int l,int r){
    return sum[r]-sum[l]-(a[r]-a[l])*(l-1);
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++){
        int cha=a[i]-a[i-1];
        sum[i]+=sum[i-1]+cha*(i-1);
    }
    int ans=0;
    for(int l=1,r=0;l<=n;l++){
        while(r<n&&calc(l,r+1)<=m) r++;
//        cout<<l<<' '<<r<<'\n';
        ans=max(ans,r-l+1);
    }
    cout<<ans;
	return 0;
}
/*
froepen
chzx_AT AK NGOI !!!!!
*/