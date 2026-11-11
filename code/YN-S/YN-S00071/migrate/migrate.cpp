#include<bits/stdc++.h>
using namespace std;
#define AC return 0
const long N=5e5+5;
vector<long> s[N];
long sts[N];
long c,t,n,d;
long ans=0;
long dfs(long a,long b){
	bool visted[N];
	fill(visted,visted+n,true);
	queue<long> syt;
	vector<long> cmm;
	long cne=0;
	syt.push(a);
	while(!syt.empty()){
		while(!syt.empty()){
			long v=syt.front();
			syt.pop();
			if(sts[v]==sts[b]){
				return cne;
			}
			
			visted[v]=false;
			cmm.push_back(v);	
		}
	
		for(long u:cmm){
			for(long x:s[u]){
				if(visted[x]){
					syt.push(x);
				}
			}
		}
		cne++;
		cmm.clear();
	}
	return -1;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(long i=1;i<=t;i++){
		cin>>n>>d;
		for(long j=1;j<=n;j++){
			cin>>sts[j];
			for(long nm=1;nm<j;nm++){
				if(abs(sts[j]-sts[nm])<=d){
				s[j].push_back(nm);
				s[nm].push_back(j); 	
				}
			}
		}
		for(long j=1;j<=n;j++){
			for(long jm=1;jm<=n;j++){
				if(jm!=j){
					if(dfs(j,sts[jm])==dfs(jm,sts[j]) && dfs(j,sts[jm])!=-1){
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
