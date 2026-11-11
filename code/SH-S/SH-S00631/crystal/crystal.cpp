#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+9;
int n,m,a[N],ans,f[N],k,b[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	ans=1;k=1;b[1]=1;
	for(int i=2;i<=n;i++){
		f[i]=f[i-1]+(i-k)*(a[i]-a[i-1]);
		while(f[i]>m){
			f[i]-=(a[i]-a[k]);
			k++;
		}
		b[i]=k;
//		cout<<i<<' '<<f[i]<<' '<<b[i]<<'\n';
		ans=max(ans,i-k+1);
	}
	cout<<ans;
	return 0;
}
