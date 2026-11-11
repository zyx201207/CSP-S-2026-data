#include<bits/stdc++.h>
using namespace std;
const int N=505,M=1e5+5;
long long c,n,m,d,q,w[N],k[M],ans=1e17,cnt;
vector<int>a[N],t[N];
void dfs(long long x,long long f,long long y,long long s,long long mey){
	if(cnt>=N){
		return;
	}
	if(s>=ans){
		return;
	}
	if(x==y&&!f){
		ans=min(ans,s);
		return;
	}else if(f&&x==y){
		cnt++;
		dfs(x,0,y,s+w[x],0);
	}else if(!f&&x!=y){
		cnt++;
		dfs(x,1,y,s+w[x],0);
	}else if(!mey&&f&&x!=y){
		for(int i=1;i<=n;i++){
			for(int j=0;j<a[i].size();j++){
				cnt++;
				if(x==a[i][j]){
					dfs(x,1,y,s+t[i][j],i);
					if(cnt>=M){
						return;
					}
				}
			}
		}
	}else if(mey){
		for(int i=1;i<=k[mey];i++){
			cnt++;
			dfs(a[mey][i],1,y,s+t[mey][i],0); 
			if(cnt>=M){
				return;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1,x;i<=n;i++){
		cin>>k[i];
		for(int j=1,y,z;j<=k[i];j++){
			cin>>y>>z;
			a[i].push_back(y);
			t[i].push_back(z);
		}
	}
	for(int i=1,x,y;i<=q;i++){
		ans=1e17,cnt=0;
		cin>>x>>y;
		dfs(x,0,y,0,0);
		cout<<ans<<"\n";
	} 
	return 0;
}
//DFS±©Á¦£¬0~10 
