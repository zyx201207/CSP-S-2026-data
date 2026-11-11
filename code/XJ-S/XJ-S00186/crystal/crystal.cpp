#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m;
int a[N],sum[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int ans=0;
	for(int l=1,r=1;l<=n&&r<=n;r++){
		int len=r-l+1;
		int x=a[r]*len-(sum[r]-sum[l-1]);
		while(x>m&&l<=r){
			l++;
			len--;
			x=a[r]*len-(sum[r]-sum[l-1]);
		}
		if(x<=m)ans=max(ans,len);
	}
	cout<<ans;
	return 0;
}
