#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int an[N],bn[N];
vector<int>vn[N];
int ans=1e9,cnt,lock=0;
void dfs(int x,int g,int lj){
	if(x==g){
		ans=min(ans,lj);
		return;
	}
	for(int i=0;i<vn[x].size();i++){
		dfs(vn[x][i],g,lj+1);
	}
}
void bfs(int x,int g,int lj){
	if(x==g){
		if(lj==ans)cnt++;
		return;
	}
	for(int i=0;i<vn[x].size();i++){
		bfs(vn[x][i],g,lj+1);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n,d;
		cin>>n>>d;
		//cout<<n<<" "<<d<<"\n";
		lock=0,ans=1e9,cnt=0;
		for(int i=1;i<=n;i++){
			cin>>an[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(an[j]-an[i]<=d)vn[i].push_back(j);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=1e9,cnt=0;
				dfs(i,j,0);
				bfs(i,j,0);
				if(cnt==2)lock++;
			}
		}
			cout<<lock<<"\n";
	}
	return 0;
}


