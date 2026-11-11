#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6+100;
int F[N];
bool ok;
int p=-1;
int s,ans,d,n;
void dfs(int x,int g){
	if(ok&&g>p) return;
	if(ok&&g==p&&x!=s) return;
    if(x==s){
		ok=1;
		p=g;
		ans++;
		return;
	}	
	if((F[s]-F[x])<=d){
		dfs(s,g+1);
		for(int i=1;i<=n;i++){
			if(i==s) continue;
			if(abs(F[x]-F[i])<=d) dfs(i,g+1);
		}
		return;
	}
	if(F[s]>F[x]){
		 for(int i=n;i>=1;i--) if(abs(F[i]-F[x])<=d) dfs(i,g+1);
		 return;
	 }
	for(int i=1;i<=n;i++) if(abs(F[i]-F[x])<=d) dfs(i,g+1);
	return;
	
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int aans=0;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>F[i];
		for(int i=1;i<n;i++){
			s=i;
			for(int j=i+1;j<=n;j++){
				ans=0;
				ok=0;
				p=-1;
				dfs(j,0);
				if(ans==2) aans++;
				//cout<<i<<" "<<j<<aans;
			}
		}
		cout<<aans<<'\n';
	}
	return 0;
}
