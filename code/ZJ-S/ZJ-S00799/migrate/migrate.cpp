#include<bits/stdc++.h>
using namespace std;
int c,t,n,D;
const int N=5e3+10;
int a[N],ans;
struct node{
	int w,t;
}d[N][N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>D;
		ans=0;
		memset(d,0x7f,sizeof d);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			int j=i+1;
			while(a[j]-a[i]<=D&&j<=n){
				d[i][j].w=1;
				d[i][j].t=1;
				j++;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				//if(a[j]-a[i]>D)break;
				for(int k=j+1;k<=n;k++){
					//if(a[k]-a[j]>D)break;
					if(d[i][j].w +d[j][k].w<d[i][k].w){
						d[i][k].w=d[i][j].w+d[j][k].w;
						d[i][k].t=1;
					}else if(d[i][j].w +d[j][k].w==d[i][k].w){
						d[i][k].t++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				if(d[i][j].t==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
}
