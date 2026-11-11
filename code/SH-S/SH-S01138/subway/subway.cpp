#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
struct Zt{
	int ind;
	long long t[22],l[22];
}zt[500005];
vector<pair<int,int>> p[505];
long long path[505][505],tp,tpt,tpz,c,n,m,d,q,ts[500005],ans;
bool vis[505];
void OshamaScramble(){
	//Let's 牛乳 dance! 
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(path[i][j]<1e10){
				p[i].push_back({j,path[i][j]});
				p[j].push_back({i,path[i][j]});
			}
		}
	}
	int pl;
	for(int i=1;i<=n;i++){
		pl=i;
		vis[i]=true;
		for(int j=2;j<=n;j++){
			for(pair<int,int> pa:p[pl]){
				if(!vis[pa.first])
					path[i][pa.first]=min(path[i][pa.first],path[i][pl]+pa.second);
			}
			pl=0;
			for(int k=1;k<=n;k++){
//				if(j<i+1){
//					pl=j-1;
//					break;
//				}
				if(!vis[k]&&path[i][pl]>path[i][k]){
					pl=k;
				}
			}
			vis[pl]=true;
		}
		memset(vis,0,sizeof(vis));
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(path,0x3f,sizeof(path));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>ts[i];
	}
	for(int i=1;i<=n;i++){
		cin>>tp;
		while(tp--){
			cin>>tpz>>tpt;
			zt[tpz].t[++zt[tpz].ind]=tpt;
			zt[tpz].l[zt[tpz].ind]=i;
		}
	}
	for(int i=1;i<=m;i++){
		if(zt[i].ind==1){
			continue;
		}
		for(int j=1;j<=zt[i].ind;j++){
			for(int k=j+1;k<=zt[i].ind;k++){
//				cout<<i<<endl<<zt[i].l[j]<<' '<<zt[i].t[j]<<endl<<zt[i].l[k]<<' '<<zt[i].t[k]<<endl<<endl;
				path[zt[i].l[j]][zt[i].l[k]]=min(zt[i].t[j]+zt[i].t[k],path[zt[i].l[j]][zt[i].l[k]]);
				path[zt[i].l[k]][zt[i].l[j]]=path[zt[i].l[j]][zt[i].l[k]];
			}
		}
	}
	for(int i=1;i<=n;i++){
		path[i][i]=0;
	}
	OshamaScramble();
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<path[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=q;i++){
		ans=path[0][0];
		cin>>n>>m;
		for(int j=1;j<=zt[n].ind;j++){
			for(int k=1;k<=zt[m].ind;k++){
				if(ans==zt[n].t[j]+zt[m].t[k]){
					break;
				}
				ans=min(ans,path[zt[n].l[j]][zt[m].l[k]]+zt[n].t[j]+zt[m].t[k]);
			}
		}
		cout<<(ans+ts[n]+ts[m])<<'\n';
	}
	return 0;
}
//不知道为什么写到tpz了 总之tpz牛掰 
