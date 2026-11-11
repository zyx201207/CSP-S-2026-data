#include<bits/stdc++.h>
using namespace std;
#define re register
#define ll long long
#define forl(i,a,b) for(re ll i=a;i<=b;i++)
#define forr(i,a,b) for(re ll i=a;i>=b;i--)
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define pb push_back
#define x first
#define y second
ll c;
ll n,m,a[2000010],ans;
ll nxt[2000010];
ll b[2000010],k;
ll f[2000010],g[2000010];
void solve(ll l,ll r){
//	cerr<<"<"<<l<<' '<<r<<endl;
	forl(i,l,r){
		k=0;
		b[++k]=i;
		ll S=0;
		forl(j,l+1,r){
			while(b[k]<j){
				b[k+1]=nxt[b[k]],k++;
				if(k>=4 && a[b[k-1]]-a[b[k-2]-1]<=m && b[k-2]-1>b[k-3]) S++;
				if(k>=4 && a[b[k-1]]-a[b[k-2]-2]<=m && b[k-2]-2>b[k-3]) S++;
				if(k>=4 && a[b[k-1]]-a[b[k-1]-1]<=m && a[b[k-1]-1]-a[b[k-2]-1]<=m && a[b[k-2]-1]-a[b[k-3]]<=m && b[k-2]-1>b[k-3]) lst++;
			}
			ll lst=S;
			if(k>=3 && a[j]-a[b[k-1]-1]<=m && b[k-1]-1>b[k-2]) lst++;
			if(k>=3 && a[j]-a[b[k-1]-2]<=m && b[k-1]-2>b[k-2]) lst++;
			if(k>=4 && a[j]-a[b[k-1]-1]<=m && a[b[k-1]-1]-a[b[k-2]-1]<=m && a[b[k-2]-1]-a[b[k-3]]<=m && b[k-2]-1>b[k-3]) lst++;
//			cerr<<a[j]-a[b[k-1]-1]<<' '<<a[j]-a[b[k-1]-2]<<endl;
//			cerr<<"<<<"<<i<<' '<<j<<' '<<lst<<endl;
			ans+=lst==1;
		}
	}
}
void Brute(){
	forl(i,1,n){
		forl(j,0,n) f[j]=1e18,g[j]=0;
		f[i]=0,g[i]=1;
		forl(j,i+1,n){
			forl(k,i,j-1) if(a[j]-a[k]<=m){
				if(f[j]>f[k]+1) f[j]=f[k]+1,g[j]=g[k];
				else if(f[j]==f[k]+1) g[j]+=g[k];
			}
		}
		forl(j,i+1,n) if(g[j]==2){
			ll R=j;
			while(R<n && g[R+1]==2) R++;
			cerr<<i<<' '<<j<<' '<<R<<endl;
			ans+=R-j+1;
			j=R;
		}
		forl(j,i,n) cerr<<g[j]<<" \n"[j==n];
	}
	cout<<ans<<endl;
}
/*
1 6 6
1 1 1 1 3 2 1 6 3 1
2 7 7
1 1 1 1 3 2 1 6 3
3 8 8
1 1 1 1 3 2 1 6
4 9 9
1 1 1 1 3 2 1
5 10 10
1 1 1 1 3 2
1 1 1 1 3
1 1 1 1
1 1 1
1 1
1
*/
void Solve(){
	ans=0;
	cin>>n>>m;
	forl(i,1,n) cin>>a[i];
	if(n>1e5) return ;
//	Brute();
//	return ;
	ll lst=1,R=1;
	forl(i,1,n){
		while(R<n && a[R+1]-a[i]<=m) R++;
		nxt[i]=R;
		if(i==R) solve(lst,R),lst=R+1;
	}
//	forl(i,1,n) cerr<<nxt[i]<<" \n"[i==n];
	cout<<ans<<endl;
//	exit(0);
}
int main(){
	freopen("migrate6.in","r",stdin);
	freopen("migrate.out","w",stdout);
	IOS;
	ll t=1;
	cin>>c>>t;
	while(t--) Solve();
	return 0;
}
