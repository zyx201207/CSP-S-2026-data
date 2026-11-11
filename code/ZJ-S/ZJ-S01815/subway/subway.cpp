#include<bits/stdc++.h>
using namespace std;//d^2*m希望可以过 
long long c,n,m,d,q,w[500005],k,N,T,t1,t2,too,x,tpnum,tpdis,TO,L,x1,x2,d1,d2,ANS,time1,time2;
struct st{
	long long num,t;
};
vector<st>a[500005];
struct ste{
	long long to,l;
};
long long e[505][505];
vector<ste> E[505];
struct st2{
	long long num,dis;
	friend bool operator<(st2 xx,st2 yy){
		return xx.dis>yy.dis;
	}
};
priority_queue<st2>P;
bool vis[505];
void cl(){
	while(!P.empty())P.pop();
	for(int i=1;i<=n;i++)vis[i]=0;
}
long long dis[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			e[i][j]=LLONG_MAX;
			dis[i][j]=LLONG_MAX;
		}
		e[i][i]=0;
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>N>>T;
			a[N].push_back(st{i,T});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<a[i].size();j++){
			x=a[i][j].num;
			t1=a[i][j].t;
			for(int k=j+1;k<a[i].size();k++){
				too=a[i][k].num;
				t2=a[i][k].t;
				//cout<<t1<<" "<<t2<<endl;
				e[x][too]=min(t1+t2,e[x][too]);
				e[too][x]=min(t1+t2,e[too][x]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j&&e[i][j]!=LLONG_MAX){
				E[i].push_back(ste{j,e[i][j]});
			}
		}
	}
	for(int i=1;i<=n;i++){
		cl();
		P.push(st2{i,0});
		while(!P.empty()){
			tpnum=P.top().num;
			tpdis=P.top().dis;
			P.pop();
			if(vis[tpnum]==0){
				vis[tpnum]=1;
				dis[i][tpnum]=tpdis;
				for(int j=0;j<E[tpnum].size();j++){
					TO=E[tpnum][j].to;
					L=E[tpnum][j].l;
					if(vis[TO]==0)P.push(st2{TO,L+tpdis});
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x1>>x2;
		ANS=LLONG_MAX;
		for(int j=0;j<a[x1].size();j++){
			d1=a[x1][j].num;
			time1=a[x1][j].t;
			for(int k=0;k<a[x2].size();k++){
				d2=a[x2][k].num;
				time2=a[x2][k].t;
				//cout<<a[x2][k].num<<" "<<a[x2][k].t<<endl;
				if(d1==d2)dis[d1][d2]=0;
				//cout<<d1<<" "<<d2<<" "<<time2<<endl;
				ANS=min(ANS,dis[d1][d2]+time1+time2+w[x1]+w[x2]);
			}
		}
		cout<<ANS<<endl;
	}
}
/*0 3 7 20 2
 8 3 6 1 7 2 9
 3 1 4 2 5 5 100
 3 2 6 3 1 7 2
 4 3 2 5 100 4 6 6 7
 1 6
 2 3

*/