#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N=2000006,INF=3e18+9;
ll c,T,n,d,x[N];
ll fmn[303][303],fcnt[303][303];
void solveBF(){
	ll ans=0;
	for(ll i=1;i<=n;++i){
		for(ll j=1;j<=n;++j){
			fmn[i][j]=INF;
			fcnt[i][j]=0;
		}
	}
	for(ll i=1;i<=n;++i){
		fmn[i][i]=0;
		fcnt[i][i]=1;
		for(ll j=1;j<i;++j){
			if(x[i]-x[j]<=d){
				for(ll k=1;k<=j;++k){
					if(fmn[k][j]+1<fmn[k][i]){
						fmn[k][i]=fmn[k][j]+1;
						fcnt[k][i]=fcnt[k][j];
					}
					else if(fmn[k][j]+1==fmn[k][i]){
						fcnt[k][i]+=fcnt[k][j];
						if(fcnt[k][i]>3)fcnt[k][i]=3;
					}
				}
			}
		}
		for(ll j=1;j<i;++j){
			if(fcnt[j][i]==2)ans++;
		}
	}
	cout<<ans<<"\n";
}
ll g[N],h[N],pre[N],nxt[N];
void solve(){
	for(ll i=0;i<=n+2;++i){
		g[i]=h[i]=pre[i]=nxt[i]=0;
	}
	x[0]=-INF-9;
	x[n+1]=INF+9;
	for(ll i=1;i<=n;++i){
		g[i]=1;
		ll k=i,le=1,ri=i-1;
		while(le<=ri){
			ll mid=(le+ri)>>1;
			if(x[i]-x[mid]<=d){
				k=mid;
				ri=mid-1;
			}
			else{
				le=mid+1;
			}
		}
		pre[i]=k;
		if(k>=i)continue;
		ll o=i+1;
		if(i<n){
			le=1,ri=i;
			while(le<=ri){
				ll mid=(le+ri)>>1;
				if(x[i+1]-x[mid]<=d){
					o=mid;
					ri=mid-1;
				}
				else{
					le=mid+1;
				}
			}
		}
		o=min(o,i);
		if(k>=o)continue;
		g[i]+=g[k];
		if(k+1<=o-1){
			g[i]+=(o-1)-(k+1)+1;
		}
	}
	pre[n+1]=n+1;
	for(ll i=n;i>=1;--i){
		h[i]=1;
		ll k=i,le=i+1,ri=n;
		while(le<=ri){
			ll mid=(le+ri)>>1;
			if(x[mid]-x[i]<=d){
				k=mid;
				le=mid+1;
			}
			else{
				ri=mid-1;
			}
		}
		nxt[i]=k;
		if(k<=i)continue;
		ll o=i-1;
		if(i>1){
			le=i,ri=n;
			while(le<=ri){
				ll mid=(le+ri)>>1;
				if(x[mid]-x[i-1]<=d){
					o=mid;
					le=mid+1;
				}
				else{
					ri=mid-1;
				}
			}
		}
		o=max(o,i);
		if(o>=k)continue;
		h[i]+=h[k];
		if(o+1<=k-1){
			h[i]+=(k-1)-(o+1)+1;
		}
	}
	nxt[0]=0;
	ll ans=0;
	for(ll k=1;k<n;++k){
		ll mnu=pre[k+1],mxu=min(k-1,pre[k+2]-1),mnv=max(k+2,nxt[k-1]+1),mxv=nxt[k];
		ll cntu=0,cntv=0;
		if(mnu>mxu||mnv>mxv)continue;
		if(mnu<=mxu){
			ll u=mnu;
			if(pre[k]<u)cntu++;
			else cntu+=g[u];
			if(mnu+1<=mxu){
				cntu+=mxu-(mnu+1)+1;
			}
		}
		if(mnv<=mxv){
			if(mnv<=mxv-1){
				cntv+=(mxv-1)-mnv+1;
			}
			ll v=mxv;
			if(nxt[k+1]>v)cntv++;
			else cntv+=h[v];
		}
		ans+=cntu*cntv;
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(ll i=1;i<=n;++i){
			cin>>x[i];
		}
		if(1<=c&&c<=6&&n<=300)solveBF();
		else solve();
	}
	return 0;
}
