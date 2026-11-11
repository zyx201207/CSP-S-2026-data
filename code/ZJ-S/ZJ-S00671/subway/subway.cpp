#include<bits/stdc++.h>
using namespace std;
const int M = 5e5+5;
const int N = 505;
long long rin(){
	long long ans = 0;
	char t = getchar();
	while(t<'0'||t>'9')t=getchar();
	while(t>='0'&&t<='9'){
		ans = ans*10+t-'0';t=getchar();
	}
	return ans;
}
void rout(long long d){
	if(d/10)rout(d/10);
	putchar('0'+d%10);
}
int c,n,m,d,q;
long long ext[M];
long long mp[N][N];
vector<pair<int,int> >vec[M];
int main(){
//	freopen("subway7.in","r",stdin);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=rin();n=rin();m=rin();d=rin();q=rin();
	for(int i = 1;i<=m;i++){
		cin>>ext[i];
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(i==j)mp[i][j]=0;
			else mp[i][j] = 1e14;
		}
	}
	for(int i = 1;i<=n;i++){
		int k;k=rin();
		for(int j = 1;j<=k;j++){
			int w,hp;w=rin();hp=rin();
			vec[w].push_back({i,hp});
		}
	}
	//get the edge val between extend node
	for(int i = 1;i<=m;i++){
		for(int j = 0;j<vec[i].size();j++){
			int u = vec[i][j].first;long long uval = vec[i][j].second;
			for(int k = j+1;k<vec[i].size();k++){
				int v = vec[i][k].first;long long vval = vec[i][k].second;
				mp[u][v] = min(mp[u][v],uval+vval);
				mp[v][u]=mp[u][v];
			}
		}
	}
	//floyd
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			for(int k = 1;k<=n;k++){
				mp[j][k] = min(mp[j][k],mp[j][i]+mp[i][k]);
			}
		}
	}
	while(q--){
		int u,v;u=rin();v=rin();
		long long ans = 1e16;
		for(auto i : vec[u]){
			for(auto j : vec[v]){
				ans = min(ans,mp[i.first][j.first]+i.second+j.second);
			}
		}
		rout(ans+ext[u]+ext[v]);putchar('\n');
	}
	return 0;
}

