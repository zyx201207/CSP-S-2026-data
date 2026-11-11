#include <iostream>
using namespace std;
const int 
int c,t;
int n,k;
int a[N][N];
int d[N];
int u,v;
int main(){
	freopen("hub.in",r,stdin);
	freopen("hub.out",w,stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=0;i<=n;++i){
			for(int j=0;j<=n;++j){
				a[i][j]=1e9;
			}
		}
		for(int i=1;i<n;++i){
			cin>>u>>v;
			a[u][v]=a[v][u]=1;
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				for(int k=1;k<=n;++k){
					if(i!=j){
						a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
					}
				}
			}
		}
		for(int i=1;i<=n;++i){
			d[i]=1e9;
			for(int j=1;j<=n;++j){
				d[i]=min(d[i],a[i][j]);
			}
		}
		sort(d+1,d+1+n,cmp);
		cout<<d[k]<<endl;
	}
	return 0;
}
