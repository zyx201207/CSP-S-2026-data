#include "bits/stdc++.h"
#define int long long
#define REP(i,j,k) for(long long i=j;i<=k;i++)
#define gc() getchar()
#define pc(i) putchar(i)
using namespace std;

typedef pair<int,int> pii;

const int MAXN=2e6+20;
int Cc,T,n,d,a[MAXN];
int xz[MAXN],nxt[MAXN];
int las[MAXN],md[MAXN],pd[MAXN];
set<pii> st;
set<pii> bst;

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0) -> ios::sync_with_stdio(0);
	cin>>Cc>>T;
	while(T--){
		if(Cc>10){
			cout<<0<<'\n';continue;
		}
		REP(i,1,n){
			a[i]=0;pd[i]=0;md[i]=0;
		}
		st.clear();bst.clear();
		cin>>n>>d;
		if(d==1){
			cout<<0<<'\n';continue;
		}
		REP(i,1,n){
			cin>>a[i];
		}
		int lasp=1;
		REP(i,1,n){
			while(a[i]-a[lasp]>d){
				lasp++;
			}
			md[i]=lasp;pd[lasp]=i;
		}
		REP(i,lasp+1,n){
			pd[i]=n+1;
		}
		int ans=0;
		REP(i,2,n-2){
			REP(l,md[i+1],i-1){
				REP(r,max(pd[l+1],i+2),pd[i]){
					if(r==n+1){break;}
					if(bst.find({l,r})!=bst.end()){
						continue;
					}else if(st.find({l,r})!=st.end()){
						st.erase({l,r});
						bst.insert({l,r});
						ans--;
					}else{
						st.insert({l,r});ans++;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}