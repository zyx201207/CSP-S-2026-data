#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+15;
int c,T;
int n,d;
int a[N],ans;
int len[N];
int b[N];
void solve1(){
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++) len[j]=1e18,b[j]=0;
		b[i]=1;
		for(int j=i+1,k=i;j<=n;j++){
			while(a[j]-a[k]>d) k++;
			if(j==k) break;
			len[j]=len[k]+1;
			b[j]=b[k];
			if(len[k+1]==len[k]) b[j]+=b[k+1];
			if(len[k+2]==len[k]) b[j]+=b[k+2];
			if(b[j]==2) ans++;
		}
	}
	cout<<ans<<'\n';
}
void solve2(){
	for(int j=1;j<=n;j++) len[j]=1e18,b[j]=0;
	b[1]=1;
	for(int j=2,k=1;j<=n;j++){
		while(a[j]-a[k]>d) k++;
		if(j==k) break;
		len[j]=len[k]+1;
		b[j]=b[k];
		if(len[k+1]==len[k]) b[j]+=b[k+1];
		if(len[k+2]==len[k]) b[j]+=b[k+2];
		if(b[j]==2) ans+=n-j+1;
	}
	cout<<ans<<'\n';
}
void solve(){
	scanf("%lld%lld",&n,&d);
	ans=0;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	if(n<=1e4) solve1();
	else solve2();
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--) solve();
	return 0;
} 
