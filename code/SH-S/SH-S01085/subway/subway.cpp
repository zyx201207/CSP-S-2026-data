#include<bits/stdc++.h>
using namespace std;
int id[509][500009];
long long c,n,m,d,q,w[500009],ans=4e18;
struct line{
	long long st,time;
};
vector<line> cost[509];
struct station{
	long long L,A;
};
vector<station> to[500009];
bool vst[509][500009];
void search(long long pos,long long li,long long arr,long long cst){
	if(cst>=ans){
		return;
	}
	if(pos==arr){
		ans=min(cst+cost[li][id[li][pos]].time,ans);
		return;
	}
	vst[li][pos]=1;
	for(int i=0;i<=to[pos].size()-1;i++){
		if(vst[to[pos][i].L][to[pos][i].A]){
			continue;
		}
		if(to[pos][i].L==li){
			search(to[pos][i].A,li,arr,cst);
		}
		else{
			cst+=cost[to[pos][i].L][id[to[pos][i].L][to[pos][i].A]].time;
			cst+=cost[to[pos][i].L][id[to[pos][i].L][pos]].time;
			search(to[pos][i].A,to[pos][i].L,arr,cst);
			cst-=cost[to[pos][i].L][id[to[pos][i].L][to[pos][i].A]].time;
			cst-=cost[to[pos][i].L][id[to[pos][i].L][pos]].time;
		}
	}
	vst[li][pos]=0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,b;
			cin>>a>>b;
			cost[i].push_back({a,b});
			id[i][a]=j-1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=cost[i].size()-1;j++){
			for(int k=j+1;k<=cost[i].size()-1;k++){
				to[cost[i][j].st].push_back({i,cost[i][k].st});
				to[cost[i][k].st].push_back({i,cost[i][j].st});
			}
		}
	}
	for(int i=1;i<=q;i++){
		int l,r;
		cin>>l>>r;
		ans=4e18;
		for(int j=0;j<=to[l].size()-1;j++){
			search(l,to[l][j].L,r,cost[to[l][j].L][id[to[l][j].L][to[l][j].A]].time);
		}
		ans+=w[l]+w[r];
		cout<<ans<<endl;
	}
	return 0;
}
