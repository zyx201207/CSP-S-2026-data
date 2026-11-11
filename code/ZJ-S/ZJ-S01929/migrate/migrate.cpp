#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,T;
int n,d,x[N],f[N],g[N],t[N];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	if(c<=10){
		int ans=0;
		for(int l=1;l<=n;l++){
			for(int i=1;i<=n;i++)f[i]=0,g[i]=0;
			int p=l;
			g[l]=1;
			for(int i=l+1;i<=n;i++){
				int k=x[i]-x[p];
				while(k>d&&p<i)p++,k=x[i]-x[p];
				if(p==i)break;
				f[i]=f[p]+1;
				g[i]=g[p];
				if(f[p]==f[p+1])g[i]+=g[p+1];
				if(f[p]==f[p+1]&&f[p+1]==f[p+2])g[i]=g[p+2];
				if(g[i]==2)ans++;
			}
		}cout<<ans<<endl;
	}else if(c<=12){
		int k=x[2]-x[1];
		if(d<2*k)cout<<"0\n";
		else {
			int len=d/k*2;
			cout<<max(0ll,n-len+1)<<endl;
		}
	}else if(c<=14){
		int ans=0;
		for(int i=1;i<=n;i++)t[i]=0;
		int p=1;
		for(int i=1;i<=n;i++){
			while(x[p+1]-x[i]<=d&&p<n)p++;
			t[p]++;
		}p=n;
		for(int i=n;i;i--){
			while(x[i]-x[p-1]<=d&&p>1)p--;
			ans+=t[p+1];
		}cout<<ans<<endl;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--)solve();
	return 0;
}/*
0 1
8 7
1 3 5 7 9 11 13 15
*/
