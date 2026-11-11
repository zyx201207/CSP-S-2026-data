#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],h[N];
int t[N];
/*
蒟蒻终于在15点23分切掉这题了
*/
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=n;i>=2;i--) h[i]=a[i],a[i]-=a[i-1];
	h[1]=a[1];
//	for(int i=1;i<=n;i++) cerr<<a[i]<<" ";
//	cerr<<"\n";
	int ans=0;
	for(int i=2,j=1;i<=n;i++){
		t[i]=t[i-1]+a[i]*(i-j);
//		cerr<<t[i]<<"\n";
		if(t[i]<=m){
			ans=max(ans,i-j+1);
		}else{
			while(t[i]>m&&j<i){
//				cerr<<"h[i]: "<<h[i]<<"  h[j]: "<<h[j]<<"\n";
				t[i]-=((h[i]-h[j]));j++;
//				cerr<<"t[i]: "<<t[i]<<"\n";
			}
			ans=max(ans,i-j+1);
		}
//		cerr<<t[i]<<" "<<i<<" "<<j<<"\n";
	}
//	cerr<<"\n"<<ans<<"\n";
	cout<<ans<<"\n";
	return 0;
}