#include<bits/stdc++.h>
using namespace std;
struct no{
	int d,s;
};
int main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	int u,v;
	cin>>u>>v;
	while(v--){
		const int ma=2000010;
		int n,m,a[11]={},b[11]={};
		cin>>n,m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i==1)continue;
			b[i]=i;
			int j;
			for(j=i-1;j;j--){
				if(a[j]+m<a[i])break;
			}
			b[i]=j+1;
		}
		int co=0;
		for(int i=1;i<=n;i++){
			queue<no>q;
			no vis[2000010]={};
			q.push({i,2});
			vis[i].d=1;
			vis[i].s=1;
			int f=-1,c=n-1;
			while(!q.empty()){
				no g=q.front();
				if(!vis[g.d].d){
					vis[g.d].d=g.s;
					vis[g.d].s=1;
					c--;
				}else if(vis[g.d].d==g.s){
					vis[g.d].s++;
				}
				for(int j=g.d-1;j>=b[g.d];j--){
					q.push({j,g.s+1});
				}
			}
			for(int j=1;j<=n;j++){
				if(vis[j].s==2)co++;
			}
		}
		cout<<co<<endl;
	}
//	fclose(stdin);
//	fclose(stdout);
}
