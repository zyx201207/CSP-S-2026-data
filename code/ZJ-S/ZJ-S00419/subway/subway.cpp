#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int w[N],a[N][510],t[N][510],k[N],vis[N],cnt,y,c,n,m,d,q;
struct node{
	int d,num;
};
vector<node>ve[N];
void dfs(int x,int ans,int l){
	if(x==y){
//		cout<<"cnt:"<<cnt<<" ans:"<<ans<<" l="<<l<<" x="<<x<<"\n";
		cnt=min(cnt,ans+t[l][x]);
		return;
	}
	for(auto it:ve[x]){
		int d=it.d,num=it.num;
		if(!vis[d]){
//			cout<<"d:"<<d<<" ans:"<<ans<<"t[l][d]"<<t[l][d]<<"t[num][d]"<<t[num][d]<<" num:"<<num<<"\n";
			if(l!=num) dfs(d,ans+t[l][x]+t[num][x],num);
			else dfs(d,ans,num);
		} 
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","r",stdout);
//c:测试点编号,n:地铁线路数,m:地铁站数
//d:每个地铁站最多被几条线路通过,q:出新计划数 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=1;j<=k[i];j++){
			for(int l=j+1;l<=k[i];l++){
				ve[a[i][j]].push_back({a[i][l],i});
			}
		}
	}
	while(q--){
		int x,f=0,xx,yy;
		cin>>x>>y;
		cnt=w[x]+w[y];
		for(int i=1;i<=n;i++){
			f=0;
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==x){
					f++;
					xx=t[i][j];
				}
				if(a[i][j]==y){
					f++;
					yy=t[i][j];
				}
			}
			if(f==2){
				cnt+=xx+yy;
				break;
			}
		}
		if(f==2){
			cout<<cnt<<"\n";
			continue;
		}
		cnt=INT_MAX;
		for(auto it:ve[x]){
			dfs(x,w[x]+w[y]+t[it.num][x],it.num);
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
