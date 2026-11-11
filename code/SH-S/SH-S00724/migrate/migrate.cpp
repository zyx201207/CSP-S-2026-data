#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t;
ll n,d,a[2000010];
ll r[100010];
ll ds[310][310],cnt[310][310];
inline ll read(){
	char c;
	bool f=false;
	c=getchar();
	ll ret=0;
	if(c=='-')	f=true;
	else if(c>='0'&&c<='9')	ret=c-'0';
	while(1){
		c=getchar();
		if(c<'0'||c>'9'){
			if(f==false)	return ret;
			else return -ret;
		}
		else	ret*=10ll,ret+=(c-'0');
	}
}
void cl(){
	memset(r,0,sizeof(r)); memset(ds,0,sizeof(ds)); memset(cnt,0,sizeof(cnt));
}
void solve(){
	cin>>n>>d;
	for(ll i=1;i<=n;++i)	cin>>a[i];
	for(ll i=1;i<=n;++i){
		for(ll j=i+1;j<=n;++j)
			if(a[j]-a[i]>d){
				r[i]=j-1;
				break;
			}
		if(r[i]==0)	r[i]=n;
	}
	for(ll i=1;i<=n;++i)
		for(ll j=i+1;j<=n;++j){
			ll tmp=i,cnt=0,imm=false;
			while(tmp<j){
				++cnt,tmp=r[tmp];
				if(tmp==r[tmp]&&tmp<j){
					imm=true;
					break;
				}
			}
			ds[i][j]=cnt*(!imm);
		}
	for(ll i=1;i<=n;++i)
		for(ll j=i+1;j<=n;++j)
			for(ll k=i+1;k<j;++k)
				if(ds[i][k]+ds[k][j]==ds[i][j])
					++cnt[i][j];
	int ans=0;
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j){
			if(cnt[i][j]==j-i-1&&cnt[i][j]>=2)
				++ans;
//			cout<<i<<" "<<j<<" "<<cnt[i][j]<<endl;
		}
	cout<<ans<<endl;
	cl();
}
void work(){
	n=read();
	d=read();
	for(ll i=1;i<=n;++i)	a[i]=read();
	ll dv=a[2]-a[1];
	if(d/dv>=2)	printf("%lld\n",max(n-(2*(d/dv)-1),0ll));
	else puts("0");
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(); t=read();
	while(t--){
		if(c<=6)	solve();
		else if(c==11||c==12)	work();
	}
}
