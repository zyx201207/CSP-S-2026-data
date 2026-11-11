#include<bits/stdc++.h>
#define ll long long
#define mid ((t[u].l+t[u].r)>>1)
#define pii pair<ll,ll>

using namespace std;

const ll N=2e6+7;
ll c,T;
ll n,d,x[N];
pii dp[5006][5003]; 

ll G;

struct node{
	ll l,r,mi,num;
}t[N];

inline void push_up(ll u) {
	if(t[u<<1].mi==t[u<<1|1].mi) {
		t[u].mi=t[u<<1].mi;
		t[u].num=t[u<<1].num+t[u<<1|1].num;
	}
	if(t[u<<1].mi<t[u<<1|1].mi) {
		t[u].mi=t[u<<1].mi;
		t[u].num=t[u<<1].num;
	}
	if(t[u<<1].mi>t[u<<1|1].mi) {
		t[u].mi=t[u<<1|1].mi;
		t[u].num=t[u<<1|1].num;
	}
}

inline void build(ll u,ll L,ll R) {
	
	t[u].l=L,t[u].r=R;
	t[u].mi=1e10;
	t[u].num=0;
	
	if(L==R) return ;
	
	build(u<<1,L,mid),build(u<<1|1,mid+1,R);
	push_up(u);
	
}

inline pii query(ll u,ll L,ll R) {
	
	pii qRES;
	
	if(t[u].l>=L&&t[u].r<=R) {
		qRES.first=t[u].mi;
		qRES.second=t[u].num;
//		if(G) cout<<t[u].l<<' '<<t[u].r<<' '<<t[u].mi<<' '<<t[u].num<<'\n';
		return qRES;
	}
	
	if(L<=mid&&R>mid) {
		
		pii res=query(u<<1,L,mid);
		pii res_=query(u<<1|1,mid+1,R);
		
		if(res.first==res_.first) {
			qRES=res;
			qRES.second+=res_.second;
			return qRES;
		}
		if(res.first<res_.first) {
			return res;
		}
		if(res.first>res_.first) {
			return res_;
		}
	}
	if(L<=mid) {
		return query(u<<1,L,R);
	}
	return query(u<<1|1,L,R);
	
}

inline void update(ll u,ll x,ll y,ll Y) {
	
	if(t[u].l==t[u].r) {
		t[u].mi=y,t[u].num=Y;
		return ;
	}
	
	if(x<=mid) update(u<<1,x,y,Y);
	if(x>mid) update(u<<1|1,x,y,Y);
	
	push_up(u);
	
}

int main() {
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>c>>T;
//	if(c<=10) {
		while(T--) {
			
			cin>>n>>d;
			for(ll i=1;i<=n;++i) {
				
				cin>>x[i];
				
			}
			
			pii FF,FF_;
			FF.first=0,FF.second=1;
			FF_.first=n*10,FF_.second=0;
			for(ll i=1;i<=n;++i) {
				dp[i][i]=FF;
				
				ll lim=i;
				
				build(1,1,n);
				update(1,i,0,1);
				
				ll F=0;
				for(ll j=i+1;j<=n;++j) {
					
					dp[i][j]=FF_;
					if(x[j]-x[j-1]>d||F) {
						F=1;
						continue;
					}
					
					while(x[j]-x[lim]>d) lim++;
//					if(i==5&&j==8) G=1,cout<<lim<<;
					dp[i][j]=query(1,lim,j-1);
					
//					 G=0;/
					dp[i][j].first++; 
					update(1,j,dp[i][j].first,dp[i][j].second);
					
				}
			}
			
			ll ans=0;
			for(ll i=1;i<n;++i) {
				for(ll j=i+1;j<=n;++j) {
					
					if(dp[i][j].second==2) ans++;
					
//					cout<<i<<' '<<j<<"  "<<dp[i][j].first<<' '<<dp[i][j].second<<'\n';
					
				}
			}
			cout<<ans<<'\n';
			
		}
//	}
		
	
	return 0;
}

/*

0 1
8 3
0 1 2 4 8 10 11 13

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

1
2


0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0
1
*/