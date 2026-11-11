#include<bits/stdc++.h>
using namespace std;
const int M=500005;
typedef long long ll;
ll c,n,m,d,p1,w[M],k,a,t[505][M/10],x,y,ans=1e14;
vector<int> q[505];
struct mode{
	ll u,o,z,f;
};
void bfs(){
	queue<mode> q1;
	q1.push({x,w[x],0,-1});
	while(!q1.empty()){
		mode r=q1.front();
		q1.pop();
		if(r.u==y){
			ans=min(r.o+w[r.u]+t[r.z][y],ans);
			continue;
		}
		if(r.o>ans) continue;
		bool tmp=1;
		for(int i=0;i<q[r.z].size();i++){
			if(!tmp||r.f!=1) q1.push({q[r.z][i],r.o,r.z,1});
		    if(q[r.z][i]==r.u) tmp=0;
		}
		for(int i=1;i<=n;i++)
		    if(t[i][r.u]!=0){
		    	if(r.f==-1)
		    	    q1.push({r.u,r.o+t[i][r.u],i,2});
		    	else q1.push({r.u,r.o+t[i][r.u]+t[r.z][r.u],i,2});
			}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p1;
	for(int i=1;i<=m;i++)
	    cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a;
			cin>>t[i][a];
			q[i].push_back(a);
		}
	}
	while(p1--){
		cin>>x>>y;
		bfs();
		cout<<ans<<endl;
	}
	return 0;
}
