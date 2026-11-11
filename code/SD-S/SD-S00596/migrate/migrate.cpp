#include<bits/stdc++.h>
using namespace std;
#define int long long
void work1();

const int N=5e3+10,N10=5e3+10;
const int INF=3e18;
const int MOD=1e9+7;
int csd,n,d,x[N],jl[N][N];
vector<int> vc[N];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	if(csd<=10){work1();return;}
}
//void work1(){
//	for(int i=1;i<=n;i++){
//		for(int j=i+1;j<=n;j++){
//			if(x[j]-x[i]<=d){
//				vc[i].push_back(j);
//			}else{
//				vc[i].push_back(j);
//				break;
//			}
//		}
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			int vs=vc[i].size(),r=i,cnt=1;
//			while(r<j){
//				for(int k=r;k<vc[i][vc[i].size()-1];k++){
//					jl[i][k]=cnt;
//				}
//				r=vc[i][vc[i].size()-1];
//				cnt++;
//			}
//			for(int k=i;k<=j;k++){
//				if(jl[k])
//			}
//		}
//	}
//}
void work1(){
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=i,ll=i;//,cnt=0;
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[j-1]>d){
				break;
			}
//			cerr<<ll<<' '<<l<<' '<<j<<'\n';
			if(x[j]-x[l]>d){
				ll=l;l=j-1;
//				jl[i][j]=jl[i][j-1]+1;
//				cerr<<ll<<' '<<l<<' '<<j<<'\n';
			}else{
//				jl[i][j]=jl[i][j-1];
			}
			if(ll<l&&l<j){
//				cerr<<ll<<' '<<l<<' '<<j<<'\n';
				if((l-1>ll&&x[l-1]-x[ll]<=d&&x[j]-x[l-1]<=d)||
					(l+1<j&&x[l+1]-x[ll]<=d&&x[j]-x[l+1]<=d)){
//						cerr<<ll<<' '<<l-1<<' '<<
//							  l+1<<' '<<j<<'\n';
					if((l-2>ll&&x[l-2]-x[ll]<=d&&x[j]-x[l-2]<=d)||
						(l+2<j&&x[l+2]-x[ll]<=d&&x[j]-x[l+2]<=d)){
//							cerr<<ll<<' '<<l-2<<' '<<
//							  l+2<<' '<<j<<'\n';
//							cerr<<x[l-2]-x[ll]<<' '<<x[j]-x[l-2]<<' '<<
//							  x[l+2]-x[ll]<<' '<<x[j]-x[l+2]<<'\n';
						break;		
					}
					if((l-1>ll&&x[l-1]-x[ll]<=d&&x[j]-x[l-1]<=d)&&
						(l+1<j&&x[l+1]-x[ll]<=d&&x[j]-x[l+1]<=d)){
//							cerr<<ll<<' '<<l-1<<' '<<
//							  l+1<<' '<<j<<'\n';
						break;		
					}
//					cnt++;
//					if(cnt>1){
//						break;
//					}
					ans++;
//					cerr<<"YES!! "<<i<<' '<<j<<'\n';
				}
			}
//			cerr<<jl[i][j]<<' ';
		}
//		cerr<<'\n';
	}
//	cerr<<"THE ANS: "<<ans<<'\n';
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>csd;
	int T=1;
	cin>>T;
	while(T--){
		solve();
	}
	
	return 0;
}
/*

*/

