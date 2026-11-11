#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int,int> >ve[500005];
int a[1000005],b[1000005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int adsafassfadas,n,m,x,y;
	cin>>adsafassfadas>>n>>m>>x>>y;
	for(int i=1;i<=m;i++){
		cin>>a[i];
		ve[i].push_back({m+i,a[i]});
		ve[m+i].push_back({i,a[i]});
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int xx,yy,u=-114514;
		for(int j=1;j<=k;j++){
			cin>>xx>>yy;
			if(u!=-114514){
				ve[m*2+xx*x+i].push_back({m*2+x*u+i,0});
				ve[m*2+x*u+i].push_back({m*2+xx*x+i,0});
			}
			u=xx;
			ve[m+xx].push_back({m*2+x*xx+i,yy});
			ve[m*2+x*xx+i].push_back({m+xx,yy});
		}
	}
	for(int i=1;i<=y;i++){
		int xx,yy;
		cin>>xx>>yy;
		queue<pair<int,int> >q;
		q.push({xx,0});
		memset(b,0,sizeof(b));
		while(!q.empty()){
			int now=q.front().first,jb=q.front().second;
			q.pop();
			b[now]=1;
			if(now==yy){
				cout<<jb<<endl;
				break;
			}
			for(auto p:ve[now]){
				if(b[p.first]){
					continue;
				}
				q.push({p.first,p.second+jb});
			}
		}
	}
	return 0;
}
