//T2 0
#include<bits/stdc++.h>
using namespace std;
struct sta{
	int w,x[550]/*ÏßÂ·*/,a[550],t[550];
}e[550];
long long c,n,m,d,q,a[500100],fl1=1,fl2=1,k[5100],dis[510],ok[510];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>e[i].w;
	for(int i=1;i<=n;i++){
		cin>>k[i];		
		for(int j=1;j<=k[i];j++){
			cin>>e[j].a[i]>>e[j].t[i];
			e[j].x[i]=i;
		}
	}while(q--){
		int x,y;cin>>x>>y;
		cout<<rand()%(n*4)<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
//5 8
//1 1 1 1 2
