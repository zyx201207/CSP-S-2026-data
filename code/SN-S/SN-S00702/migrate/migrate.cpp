#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,T;
int n,d;
const int N=2e6+10;
int a[N];
bool v[N];
map<int,bool> r;
void solve(){
	int ans=0;
	for(int i=1;i<=n;i++)r[a[i]]=false;
	for(int i=1;i<=n;i++)a[i]=0;
	
	a[0]=LLONG_MIN;
	for(int i=1;i<=n;i++)v[i]=false;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		r[a[i]]=true;
		
	}
	for(int i=1;i<=n;i++){
		if(v[i])continue;
		int tak=1;v[i]=true;
		bool ned=true;
		for(int j=a[i]+d;j<=a[n]+1;){
			if(r[j-1]){
				ans+=tak-ned;
				ned=false;
			}
			int nxt=lower_bound(a,a+n+1,j)-a;
			if(a[nxt]!=j){
				nxt--;
			}
			if(a[nxt]+d<a[nxt+1]){
				break;
			}
//			if(nxt==n)break;
			j=a[nxt]+d;
					
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		solve();
	} 
	return 0;
}
//migrate by Íõè÷·² SN-S00702
