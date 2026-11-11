#include<bits/stdc++.h>
using namespace std;
struct tion{
	int x,val;
};
vector<tion>t[500005];
int op,m,n,d,q,s,e;
int a[500005];
int sum[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>op>>m>>n>>d>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int u,y;
			cin>>u>>y;
			if(i!=u) t[i].push_back({u,y});
			t[u].push_back({i,y});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<t[i].size();j++){
			cout<<t[i][j].x<<" ";
		}
		cout<<"\n";
	}
	while(q--){
		memset(sum,0x3f,sizeof(sum));
		cin>>s>>e;
		int ans=a[s]+a[e];
		queue<tion>v;
		int oiy=0;
		for(int i=0;i<t[s].size();i++){
			if(t[s][i].x==s){
				oiy+=t[s][i].val;
			}
		}
		v.push({s,oiy});
		while(v.size()){
			int u=v.front().val,y=v.front().x;
			v.pop();
			int vu=u;
			int id=-1;
			for(int i=0;i<t[y].size();i++){
				if(t[y][i].x==s){
					u+=t[y][i].val;
					id=i;
				}
			}
			for(int i=0;i<t[y].size();i++){
				if(t[y][i].x!=s){
					if(u+t[y][i].val<sum[t[y][i].x]) {
						if(i==id) v.push({t[y][i].x,u+t[y][i].val});
						else v.push({t[y][i].x,t[y][i].val+vu});
						if(i==id) sum[t[y][i].x]=u+t[y][i].val;
						else sum[t[y][i].x]=vu+t[y][i].val;
					}
				}
			}
		}
		cout<<sum[e]+ans<<"\n";
	}
	return 0;
}/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
