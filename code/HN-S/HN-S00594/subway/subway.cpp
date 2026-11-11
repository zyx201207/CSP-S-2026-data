#include<bits/stdc++.h>
using namespace std;
int c,m,n,d,q,k[505];
bool f=0;
int w[500005];
struct str{
	int a;
	int t;
}sub[505][20005];
int x;
int y;
int cmp(str a,str b){
	return a.a<b.a;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d%d",&sub[i][j].a,&sub[i][j].t);
		}
		sort(sub[i]+1,sub[i]+k[i]+1,cmp);
	}
	while(q--){
		scanf("%d%d",&x,&y);
		int now=x;
		int time=w[x];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(now==y){
					cout<<time+w[y]<<"\n";
					break;
				}
				if(f==1){
					time+=sub[i][j].t;
					now=sub[i][j].a;
				}
				else if(sub[i][j].a==x){
					f=1;
				}
			}
			
		}
	} 
	return 0;
}
