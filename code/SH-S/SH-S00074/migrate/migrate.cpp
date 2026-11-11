#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define fi first
#define se second
#define mk make_pair
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll maxn=2000009;
const ll inf=1e18;
ll Cid,NT,n,d,a[maxn];
ll f[5009],cntf[5009],s[5009],st[5009];
void solveBF(){
	ll ans=0;
	rep(i,1,n){
		f[i]=0,cntf[i]=1;
		s[i-1]=0,s[i]=1;
		fill(st,st+1+n,0);
		st[0]=i;
		ll l=i;
		rep(j,i+1,n){
			while(a[j]-a[l]>d)	l++;
			f[j]=f[l]+1;
			if(!st[f[j]])	st[f[j]]=j;
			cntf[j]=s[st[f[j]]-1]-s[l-1];
			s[j]=s[j-1]+cntf[j];
			if(cntf[j]==2)	ans++;
		}
	}
	cout<<ans<<'\n';
}
void solveA(){
	ll del=a[2]-a[1];
	ll k=d/del;
	if(k<=1)	cout<<0<<'\n';
	else cout<<max(0ll,n-2*k+1)<<'\n';
}
ll nxt[maxn];
void solveB(){
	ll r=1,l=1,j=1,ans=0;
	rep(i,1,n){
		while(r+1<=n&&a[r+1]-a[i]<=d)	r++;
		nxt[i]=r;
	}
	rep(i,1,n){
		ll r=nxt[i];
		while(j<=n&&r-l+1>2){
			j++;
			if(j>n)	l=j;
			while(a[j]-a[l]>d)	l++;
		}
		if(j<=n&&r-l+1==2)	ans+=nxt[l]-j+1/*,cout<<i<<' '<<j<<' '<<nxt[l]<<'\n'*/;
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>Cid>>NT;
	while(NT-->0){
		cin>>n>>d;
		rep(i,1,n)	cin>>a[i];
		if(Cid<=10)
			solveBF();
		else if(Cid>=11&&Cid<=12)	solveA();
		else if(Cid>=13&&Cid<=14)
			solveB();
	}
	return 0;
}
