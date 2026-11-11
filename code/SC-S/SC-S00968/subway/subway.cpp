#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=510;
int x,y,h=0;
int c,n,m,d,q;
int w[N],a[M][M],b[M][M],v[N],k[N];
struct str{
	int s,t;
};
void fun(){
	cin>>x>>y;
	h+=w[x];
	queue<str> p;
	p.push({x,h});
	while(p.size()){
		int z=p.front().s;
		int o=p.front().t;
		p.pop();
		if(z==y){
			printf("%d",h);
			return;
		}
		if(v[z]==1) continue;
		v[z]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==z){
					for(int l=1;l<=k[i];l++){
						if(l!=j){
							p.push(a[i][l],o+b[i][j]+b[i][l]);
						}
					}
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=2*k[i];j++){
			cin>>a[i][j]>>b[i][j];
		}
	}
	while(q--){
		fun();
	}
	return 0;
}