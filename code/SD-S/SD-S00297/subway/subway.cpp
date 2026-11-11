#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int N=5e5+5;
int c,n,m,d,Q;
vector<pii> a[N];
vector<pii> e[N];
int w[N],de[N];
vector<int> id[N];//第i个站编号及所在路线 
priority_queue<pii,vector<pii>,greater<pii> > q;
int solve(int x,int y){//return
//	for(auto u:id[x]){
//		for(auto v:id[y]){
//			if(u==v) return 0;
//		}
//	}
	for(int i=1;i<=n;i++){
		de[i]=1e9;
	}
	de[x]=0;
	q.push({0ll,x});
	while(q.size()){
		pii t=q.top();
		q.pop();
		int tu=t.second,tw=t.first;
		if(tw>de[tu]) continue;
		for(auto v:a[tu]){
			int vu=v.second,vw=v.first;
			if(de[vu]>de[tu]+vw){
				de[vu]=de[tu]+vw;
				q.push({de[vu],vu});
			}
		}
	}
//	cout<<de[y]<<"\n";
	return de[y];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>Q;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int zz,tt;
			cin>>zz>>tt;
			e[i].push_back({zz,tt});
			id[zz].push_back(i);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<i;j++){
			for(auto u:e[i]){
				for(auto v:e[j]){
					int uu=u.first,uw=u.second;
					int vv=v.first,vw=v.second;
					if(uu==vv){
						a[i].push_back({uw+vw,j});
						a[j].push_back({uw+vw,i});
//						cout<<"::"<<uu<<"\n";
					}
				}
			}
		}
	}
	while(Q--){
		int x,y;
		cin>>x>>y;
//		cout<<"::"<<x<<" "<<y<<"\n";
		int aa=solve(x,y);
		if(aa>=1e9) cout<<w[x]+w[y]<<"\n";
		else cout<<w[x]+w[y]+solve(x,y)<<"\n";
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
