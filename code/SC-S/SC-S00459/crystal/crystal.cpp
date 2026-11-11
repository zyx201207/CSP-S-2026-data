#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],d[N],sum[N],mx=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) d[i]=a[i]-a[i-1];
	d[1]=0;
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+d[i]*(i-1);
	if(n<=400){
		for(int i=2;i<=n;i++) for(int j=1;j<i;j++){
			int t=0;
			bool flg=0;
			for(int k=j;k<=i;k++){
				t+=d[i]*(k-j);
				if(t>m){
					flg=1;
					break;
				}
			}
			if(flg) continue;
			if(t<=m) mx=max(mx,i-j+1);
		}
		cout<<mx;
		return 0;
	}
	for(int i=1;i<=n;i++) if(sum[i]<=m) mx=max(mx,i);
	cout<<mx;
	return 0;
}