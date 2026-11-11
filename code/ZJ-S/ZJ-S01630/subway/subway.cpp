#include<bits/stdc++.h>
using namespace std;
struct node{
	long long lx,tm;
};
long long x,y,c,n,m,d,q,a[510][50010],t,k,w[500010],mins,book[510][50010];
vector<long long> u[510][50010];
vector<node> v[500010];
void dfs(int r,long long tim,int fx,long long tlv){
	if(r==y){
		for(int i=0;i<v[fx].size();i++){
			node ft=v[fx][i];
			if(ft.lx==r){
				mins+=ft.tm;
				break;
			}
		}
		mins=min(mins,tim);
		return ;
	}
	if(tim>=mins) return ;
	for(int i=0;i<u[r][fx].size();i++){
		if(!book[r][u[r][fx][i]]){
			book[r][u[r][fx][i]]=1;
			for(int i=0;i<v[u[r][fx][i]].size();i++){
				node ft=v[u[r][fx][i]][i];
				if(ft.lx==r){
					tlv=ft.tm;
					break;
				}
			}
			dfs(r,tim,u[r][fx][i],tlv);
			book[r][u[r][fx][i]]=0;
		}
	}
	for(int i=0;i<v[x].size();i++){
		node ft=v[x][i];
		if(!book[ft.lx][fx]){
			book[ft.lx][fx]=1;
			dfs(ft.lx,tim+tlv+ft.tm,x,ft.tm);
			book[ft.lx][fx]=0;
		}
		
	}
	return ;
}
int main(){
	freopen("subway1.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t;
			v[a[i][j]].push_back({i,t});
		}
		for(int j=1;j<=k;j++){
			for(int kk=j+1;kk<=k;kk++){
				u[i][a[i][j]].push_back(a[i][kk]);
				u[i][a[i][kk]].push_back(a[i][j]);
			}
		}
	}
	while(q--){
		cin>>x>>y;
		mins=INT_MAX;
		memset(book,0,sizeof book);
		for(int i=0;i<v[x].size();i++){
			node ft=v[x][i];
			dfs(ft.lx,ft.tm,x,ft.tm);
		}
		cout<<mins+w[x]+w[y]<<"\n";
	}
	return 0;
}