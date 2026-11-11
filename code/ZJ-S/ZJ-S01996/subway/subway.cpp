#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e3+5;
vector<int> v_1[N];
int c,n,m,d,q,w[N],k[N],a[N][N],t[N][N],v_2[N][N],x,sum;
int y;
bool check(int l){
	for(int i=1;i<=k[l];i++){
		if(a[l][i]==y) return true;
	}
	return false;
}
void dfs(int x,int time){
	for(auto b:v_1[x]){//b is line ,x is station
		time+=v_2[b][x];
		if(check(b)){
			sum=max(sum,v_2[b][y]+time);
			return;
		}
		for(int i=1;i<=k[b];i++){
			if(a[b][i]!=x){
				dfs(a[b][i],time+v_2[b][a[b][i]]);
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			v_1[a[i][j]].push_back(i); //station a[i][j] have line i ;
			v_2[i][a[i][j]]=t[i][j]; //line i have station a[i][j],time t[i][j]
		}
	}
	while(q--){
		sum=0;
		cin>>x>>y;
		dfs(x,0);
		sum+=w[x]+w[y];
		cout<<sum<<endl;
	}
	return 0;
}
