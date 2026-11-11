#include<bits/stdc++.h>
using namespace std;
int dk[1001][501],c,n,m,d,q,w[500001],a[5005],t,k;
struct caoi{
	int to,la;
};
vector<caoi>v[1001];
int dfs(int id,int ed,int ld,int fa){
	if(id==ed){
		return dk[ed][ld];
	}
	cout<<ld<<'\n';
	int ans=0x3f3f3f3f;
	for(int h=0;h<v[id].size();h++){
		caoi i=v[id][h];
//		cout<<ld<<' '<<i.la<<' '<<id<<' '<<i.to<<'\n';
		if(ld==i.la){
			ans=min(ans,dfs(i.to,ed,i.la,id));
		}else{
			if(i.to!=ed)ans=min(ans,dfs(i.to,ed,i.la,id)+dk[i.to][i.la]+dk[id][ld]);
			else ans=min(ans,dfs(i.to,ed,i.la,id)+dk[i.to][i.la]+dk[id][ld]);
		}
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t;
			dk[a[j]][i]=t;
			if(j>1){
				v[a[j-1]].push_back({a[j],i});
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<dfs(x,y,0,0)+w[x]+w[y]<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/