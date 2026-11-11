#include<bits/stdc++.h>
using namespace std;
const int N=5e6+5;
int c,t,n,k=0,d;
int f[N];
int x[N],y[N];
void dfs(int x1,int y1){
	for(int i=1;i<=n;i++){
		if(abs(x[i]-x1)<=d){
			if(y[i]<y1+1)continue;
			else if(y[i]>y1+1){
				f[N]=0;
				y[i]=y1+1;
				dfs(x[i],y1+1);
			}else{
				f[N]=1;
				y[i]=y1+1;
				dfs(x[i],y1+1);
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++){
			dfs(i,0);
			for(int j=1;j<=n;j++){
				if(f[j]==1){
					f[i]=0;
					k++;
				}
			}
		}
		cout<<k<<endl;
		k=0;
	}
	return 0;
}