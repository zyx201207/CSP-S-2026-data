#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n;
char c[N];
int a[N];
int l[N],r[N];
void solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>c[i];
		l[i]=r[i-1]+1;
		r[i]=l[i]+a[i]-1;
	}
	int ans=0;
	int i=1,j=n;
	while(i<j){
		int L=1+r[n]-r[j],R=L+a[j]-1;
		while(r[i]<L){
			//cout<<i<<' '<<j<<'\n';
			++i;
		}
		if(l[i]>R){
			--j;
			continue;
		}
		if(l[i]<=R&&R<=r[i]){
			if(c[i]!=c[j]) ans+=min(R-l[i]+1,a[j]);
			//cout<<i<<' '<<j<<'\n';
			--j;
		}else{
			if(c[i]!=c[j]) ans+=min(a[i],r[i]-L+1);
			//cout<<i<<' '<<j<<'\n';
			++i;
		}
	}
	cout<<ans;
}

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	solve();
	return 0;
}


