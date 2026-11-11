#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=512345;
ll a[N],f[2][N];
ll sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ll cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i-1]!=a[i])cnt++;
		sum[cnt]++;
	}
	unique(a+1,a+1+n);
	ll s=0,x=1;
	int ans=0;
	for(int i=1;i<=cnt;i++){
		int k=sum[i];
		s+=k;
		for(int j=0;j<=k;j++){
			f[x][j]=0;
		}
		ans=max(k,ans);
		if(i>1)
			for(int j=k+1;j<=s;j++){
				f[x][j]=f[x^1][j-k]+(a[i]-a[i-1])*(j-k);
				if(f[x][j]<=m)ans=max(j,ans);
			}
		x^=1;
	}
	cout<<ans;
	return 0;
} 