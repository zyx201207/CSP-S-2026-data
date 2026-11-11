#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define rrep(i,r,l) for(int i=r;i>=l;i--)
#define fi first
#define sc second
#define pb push_back
#define pq priority_queue
using namespace std;
typedef long long ll;
const int N=2e6+5;
ll n,d;
ll A[N];
int L[N],R[N];
int F[N];
ll C0[N],C1[N],S0[N],S1[N],S2[N];
bool T[N];
void solve(){
	cin>>n>>d;
	rep(i,1,n){
		cin>>A[i];
	}
	L[0]=1;
	rep(i,1,n){
		L[i]=L[i-1];
		while(A[i]-A[L[i]]>d){
			L[i]++;
		}
	}
	R[n+1]=n;
	rrep(i,n,1){
		R[i]=R[i+1];
		while(A[R[i]]-A[i]>d){
			R[i]--;
		}
	}
//	rep(i,1,n){
//		cerr<<L[i]<<" "<<R[i]<<"\n";
//	}
	vector<int>V;
	rep(i,2,n){
		if(R[i]!=i&&R[i-1]==R[i]){
			if(R[i-2]<R[i]){
				V.pb(i);
				F[i]=1;
			}else{
				F[i]=2;
			}
		}else{
			F[i]=0;
		}
//		cerr<<F[i]<<" ";
	}
//	cerr<<"\n";
	rep(i,2,n){
		C0[i]=R[i-1]-max(R[i-2],i);
		C1[i]=R[i]-R[i-1];
	}
	ll ans=0;
	rrep(i,n,2){
		T[i]=0;
		if(R[i]==i){
			S0[i]=S1[i]=S2[i]=0;
			continue;
		}
		if(F[i]==2){
			S0[i]=C0[i];
			S1[i]=C1[i];
			S2[i]=0;
			continue;
		}
//		{
//			S0[i]=S0[R[i]];
//			S1[i]=C1[i];
//			S2[i]=C0[i];
//		}
		if(F[i]==1){
			S1[i]=C1[i];
			if(R[i-1]>=R[i]-1){
				S0[i]=S1[R[i]]+C0[i];
				S2[i]=0;
			}else{
				S0[i]=S1[R[i]]+C0[i];
				S2[i]=S1[R[i]];
			}
		}else{
			S1[i]=S1[R[i]]+C1[i];
			if(R[i-1]>=R[i]-1){
				S0[i]=S2[R[i]]+C0[i];
				S2[i]=S2[R[i]];
			}else{
				S0[i]=S0[R[i]]+C0[i];
				S2[i]=S0[R[i]];
			}
		}
	}
//	rep(i,1,n){
//		cerr<<"R["<<i<<"]="<<R[i]<<" T["<<i<<"]="<<T[i]<<" C0["<<i<<"]="<<C0[i]<<" C1["<<i<<"]="<<C1[i]<<" S0["<<i<<"]="<<S0[i]<<" S1["<<i<<"]="<<S1[i]<<"\n";
//	}
	rep(i,1,n){
		ans+=S0[R[i]];
	}
	cout<<ans<<"\n";
	return;
	cerr<<ans<<"\n";
	
	ans=0;
	rep(i,1,n){
		int cnt=0;
		int u=i;
		while(true){
			if(R[u]==u){
				break;
			}
			if(u!=i){
				if(cnt){
					ans+=C1[u];
				}else{
					ans+=C0[u];
				}
				if(F[u]==2){
					break;
				}else if(F[u]==1){
					cnt++;
					if(cnt>1){
						break;
					}
				}
			}
			u=R[u];
		}
	}
	
	cout<<ans<<"\n";
	cout<<flush;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
