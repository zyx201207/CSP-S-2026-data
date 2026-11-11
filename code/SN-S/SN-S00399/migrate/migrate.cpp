#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e6+5;
ll c,t,n,d,x[maxn],ans;
void read(ll &rd){
	rd=0;
	ll f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		rd*=10;
		rd+=c-'0';
		c=getchar();
	}
	rd*=f;
	return;
}
void solve(){
	ans=0;
	read(n);
	read(d);
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[i]<2*d){
				int cnt=0;
				for(int k=1;k<=n;k++){
					if(x[j]-d<=x[k]&&x[k]<=x[i]+d) cnt++;
				}
				if(cnt==2) ans++;
			}
		}
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read(c);
	read(t);
	while(t--) solve();
	return 0;
}
