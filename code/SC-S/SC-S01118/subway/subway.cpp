#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int c,m,n,d,q,g[10000][10000],flag;
int spfa(int gs,int rs){
	int dis[50000],v[50000];
	queue<int> qe;
	for(int i=1;i<=flag;i++) v[i]=0;
	memset(dis,0x3f,sizeof(dis));
	dis[gs]=0;
	qe.push(gs);
	while(!qe.empty()){
		int ma=qe.front();
		v[ma]=0;
		qe.pop();
		for(int i=1;i<=flag;i++){
			if(g[ma][i]!=0){
				if(dis[i]>dis[ma]+g[ma][i]){
					dis[i]=dis[ma]+g[ma][i];
					if(v[i]==0){
						qe.push(i);
						v[i]=1;
					}
				}
			}
		}
	
	}
	return dis[rs];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
cin>>c>>n>>m>>d>>q;
for(int i=1;i<=m;i++){
	int x;
	cin>>x;
	g[i][i+m]=x;
	g[i+m][i]=x;
	
}

flag=2*n+1;
for(int i=1;i<=n;i++){
	int x,bl=0;
	cin>>x;
	for(int j=1;j<=x*2;j++){
		int ax,tx;
		cin>>ax>>tx;
		g[ax+m][flag]=g[flag][ax+m]=tx;
		
		if(bl==1) g[flag][flag-1]=g[flag-1][flag]=0;
		if(j==1) bl=1;
		flag++;
	}
}
flag--;
while(q>0){
	q--;
	int w1,w2;
	cin>>w1>>w2;
	cout<<spfa(w1,w2)<<'\n';
}

	return 0;
} 