#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[2000010],di[5001],gs[5001],st[5001];
vector<int>e[5001];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(n<=5000){
			for(int i=1;i<=n;i++)e[i].clear();
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(abs(x[i]-x[j])<=d)e[i].push_back(j),e[j].push_back(i);
				}
			}
			int su=0;
			priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
			for(int i=1;i<=n;i++){
				
				for(int j=1;j<=n;j++)st[j]=0,di[j]=1000000000000000000,gs[j]=0;
				di[i]=0;
				gs[i]=1;
				p.push({0,i});
				while(p.size()){
					pair<int,int> t=p.top();
					p.pop();
					if(st[t.second]==1)continue;
					st[t.second]=1;
					for(int y:e[t.second]){
						if(di[t.second]+1<di[y]){
							di[y]=di[t.second]+1;
							gs[y]=gs[t.second];
							p.push({di[y],y});
						}
						else if(di[t.second]+1==di[y]){
							gs[y]+=gs[t.second];
						}
					}
				}
				for(int j=1;j<=n;j++){
					if(gs[j]==2)su++;
				}
			}
			cout<<su/2<<"\n";
		}
		else{
			cout<<0<<"\n";
		}
	}
	return 0;
	
	
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
