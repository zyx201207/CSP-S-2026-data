#include<bits\stdc++.h> 
using namespace std;
int sj[500005],lsm[500005],lds[500005];
vector<pair<int,int>>g[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>sj[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		cin>>lsm[1]>>lds[1];
		for(int j=2;j<=k;j++){
			cin>>lsm[j]>>lds[j];
			g[lsm[j]].push_back({lsm[j-1],lds[j-1]+lds[j]});
			g[lsm[j-1]].push_back({lsm[j],lds[j-1]+lds[j]});
		}
		g[lsm[1]].push_back({lsm[k],lds[k]+lds[1]});
		g[lsm[k]].push_back({lsm[1],lds[1]+lds[k]});
	}
	if(c<=8){
		while(q--){
			long long dir[m+5];
			int cxy,zm;
			cin>>cxy>>zm;
			queue<int>aaa;
			aaa.push(cxy);
			memset(dir,0x3f3f3f,sizeof(dir));
			dir[cxy]=0;
			while(aaa.size()){
				int nowww=aaa.front();
				aaa.pop();
				for(int i=0;i<g[nowww].size();i++){
					if(dir[nowww]+g[nowww][i].second<dir[g[nowww][i].first]){
						dir[g[nowww][i].first]=dir[nowww]+g[nowww][i].second;
						aaa.push(g[nowww][i].first);
					}
				}
			}cout<<dir[zm]+sj[zm]+sj[cxy]<<endl;
		}
	}
	return 0;
}
