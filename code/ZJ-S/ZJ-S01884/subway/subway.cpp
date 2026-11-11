#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int c,n,m,d,q;
int x,y;
int k;
int w[N];
int a[1005];
struct SSS{
	bool cg[1005];
	bool qaq;
};
SSS mp[1005][1005];
int t[1005][1005];
int ans=5e5+5;
bool vis[N];
void dfs(int pos,int k,int dst,int tm){
	if(pos==dst){
		if(tm<ans){
			ans=tm;
		}
		return ;
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]&&mp[pos][i].qaq){//can reach
			vis[i]=true;
			if(mp[pos][i].cg[k]!=true){//need to exchange
				int nw;
				for(int xl=1;xl<=n;++xl){
					if(mp[pos][i].cg[xl])
					nw=xl;
					break;
				}
				tm+=(t[k][i]+t[nw][i]);
				dfs(i,nw,dst,tm);
				vis[i]=false;
			}else{
				dfs(i,k,dst,tm);
			}
		}
	}
}
int main(){
	//QaQ
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;++i){
		cin >> w[i];
	}
	for(int i=1;i<=n;++i){
		cin >> k;
		for(int j=1;j<=k;++j){
			cin >> a[j] >> t[i][j];
		}
		for(int st=1;st<=k;++st){
			for(int j=st+1;j<=n;++j){
				mp[st][j].cg[i]=true;
				mp[j][st].cg[i]=true;
				mp[st][j].qaq=true;
				mp[j][st].qaq=true;		
			}
		}
	}
	for(int i=1;i<=q;++i){
		ans=5e5+5;
		memset(vis,false,sizeof(vis));
		cin >> x >> y;
		int mmin=200000;
		int startt;
		for(int k=1;k<=n;++k){
			if(w[k]<mmin){
				startt=k;
			}
		}
		dfs(x,startt,y,0);
		cout << ans+w[x]+w[y] << endl;
	}
	return 0;
}
