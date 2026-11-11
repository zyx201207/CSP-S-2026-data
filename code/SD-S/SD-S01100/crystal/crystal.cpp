#include<bits/stdc++.h>
#define int long long
using namespace std;
void IOS(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
const int N=5e5+5;
int n,m;
int a[N],sum[N];
bool check(int h){
	for(int l=1;l+h-1<=n;++l){
		int r=l+h-1;
		int k=h*a[r];
		int kl=sum[r]-sum[l-1];
		if(k-kl<=m)return 1;
	}
	return 0;
}
signed main(){
	IOS();
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)sum[i]=sum[i-1]+a[i];
	int l=1,r=n,ans=1;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
