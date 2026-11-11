#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y,k,t,index;
int w[500001];
multiset<pair<int,int>> p;
multiset<pair<int,int>> want;
long long ans;
void dfs(int cnt,int path,int need,long long f){
	if(cnt>d){
		return;
	}
	else if(cnt<=d&&path==need){
		ans=min(f,ans);
	}
	else{
		for(int i=path;i<2*k;i++){
			dfs(cnt+1,p[index].second,need,f+w[p[index].second]);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freout("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;//d xianzhi
	for(int i=0;i<c;i++){
		ans=1e9;
		for(int i=1;i<=m;i++){
			cin>>t;
			w[i]=t;
		}
		for(int i=0;i<n;i++){
			cin>>k;
			for(int i=0;i<2*k;i++){
				cin>>a>>t;
				p.insert({{a,t}});
			}
		}
		for(int i=0;i<q;i++){
			ans=1e9;index=i;
			cin>>x>>y;
			dfs(0,x,y,0);
			ans+=w[x]+w[y];
			cout<<ans<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
