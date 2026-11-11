#include<bits/stdc++.h>
using namespace std;
struct zt{
	int id;
	long long time;
	bool operator>(const zt&zti)const{
		return time>zti.time;
	}
};
long long c,n,m,d,q,x,y,w[500009],aa[500009][2];
vector<zt> a[500009];
long long dmin[1009][1009];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i=0;i<1009;i++)
		fill(dmin[i],dmin[i]+1009,1e17);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int ki;
		cin>>ki;
		for(int j=1;j<=ki;j++){
			cin>>aa[j][0]>>aa[j][1];
			for(int k=1;k<j;k++){
				zt zti;
				zti.id=aa[j][0];
				zti.time=aa[j][1]+aa[k][1];
				a[aa[k][0]].push_back(zti);
				zti.id=aa[k][0];
				zti.time=aa[j][1]+aa[k][1];
				a[aa[j][0]].push_back(zti);
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		bool ok[500009];
		fill(ok,ok+500009,0);
		priority_queue<zt,vector<zt>,greater<zt> > que;
		for(int j=0;j<a[x].size();j++){
			dmin[x][a[x][j].id]=a[x][j].time;
			zt zti;
			zti.id=a[x][j].id;
			zti.time=a[x][j].time;
			que.push(zti);
		}
		while(!que.empty()){
			zt zti;
			zti=que.top();
			que.pop();
			ok[zti.id]=1;
			for(int k=0;k<a[zti.id].size();k++){
				dmin[x][a[zti.id][k].id]=min(dmin[x][a[zti.id][k].id],dmin[x][zti.id]+a[zti.id][k].time);
				dmin[a[zti.id][k].id][x]=dmin[x][a[zti.id][k].id];
				zt zt1;
				zt1.id=a[zti.id][k].id;
				zt1.time=a[zti.id][k].time;
				if(ok[a[zti.id][k].id]==0) que.push(zt1);
			}
		}
		cout<<dmin[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
} 
