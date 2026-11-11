#include<bits/stdc++.h>
using namespace std;
using ll=long long;

vector<ll> tu[2000001];
ll n,d,a[2000001];
ll c,ttt;
vector<int> z;

vector<int> minn; 

void dfs(ll qd,ll zd,int cd){
	if(qd>zd){
		return ;
	}
	if(tu[qd].empty()){
		return ;
	}
	for(int i=0;i<tu[qd].size();i++){
		dfs(tu[qd][i],zd,cd+1);
	}
	if(qd==zd){
		minn.push_back(cd);
		return ;
	}
	return ;
}
int main(){
  freopen("migrate.in","r",stdin);
  freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>ttt;
	while(ttt--){
		minn.clear();
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			tu[i].clear();
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					tu[i].push_back(j);
				}else{
					break;
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				dfs(i,j,0);
				sort(minn.begin(),minn.end());  
				if((minn.size()==2&&minn[0]==minn[1])||((minn.size()>=2)&&minn[0]==minn[1]&&minn[1]!=minn[2])){
					ans++;
				}
			}
		}
		z.push_back(ans);
	}
	for(int i=0;i<z.size();i++){
		if(i==z.size()-1){
			cout<<z[i];
		}else{
			cout<<z[i]<<'\n';
		}
	}
	return 0;
}
