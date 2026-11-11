#include<bits/stdc++.h>
using namespace std;
long long c,n,m,js,d,qq,w[500006],cd[4006],ans[506][40006];
struct aaaaa{
	long long d,qz;
}ls;
vector<aaaaa> v[500006];
bool operator <(aaaaa x,aaaaa y){
	return x.qz>y.qz;
}
priority_queue<aaaaa> q;
int main()
{
	long long x,y,z=0,ww;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	js=m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&ww);
		z+=ww;
		js++;
		for(int j=0;j<ww;j++){
			scanf("%lld%lld",&x,&y);
			v[js].push_back({x,y});
			v[x].push_back({js,y});
		}
	}
	//for(int i=0;i<v[1].size();i++) cout<<v[1][i].d<<"ok";
	//if(z<=1006||c<=11){
		for(int i=m+1;i<=js;i++){
			q.push({i,0ll});
			for(int j=1;j<=js;j++) cd[j]=1e18;
			cd[i]=0;
			while(!q.empty()){
				ls=q.top();
				q.pop();
				if(cd[ls.d]!=ls.qz) continue;
				for(int j=0;j<v[ls.d].size();j++){
					if(cd[v[ls.d][j].d]>cd[ls.d]+v[ls.d][j].qz){
						cd[v[ls.d][j].d]=cd[ls.d]+v[ls.d][j].qz;
						q.push({v[ls.d][j].d,cd[v[ls.d][j].d]});
					}
				}
			}
			for(int j=1;j<=js;j++) ans[i-m][j]=cd[j];
		}
		//cout<<ans[1][3]<<"ok";
		while(qq--){
			//cout<<"ok";
			scanf("%lld%lld",&x,&y);
			z=w[x]+w[y];
			ww=1e18;
			for(int i=0;i<v[x].size();i++) ww=min(ww,ans[v[x][i].d-m][y]+v[x][i].qz);
			printf("%lld\n",ww+z);
		}
		return 0;
	//}
	
	//return 0;
}