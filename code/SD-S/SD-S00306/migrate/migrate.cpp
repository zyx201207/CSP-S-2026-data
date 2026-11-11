#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,d;
int c,t;
ll a[2000006];
ll dis[305][305];
int cn[305][305];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c<=6){
		while(t--){
			int cnt=0;
			memset(dis,0x3f3f3f3f,sizeof(dis));
			memset(cn,0,sizeof(cn)); 
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>a[i];
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(abs(a[j]-a[i])<=d){
						dis[i][j]=1;
						dis[j][i]=1;
					}
				}
			}
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					for(int k=j+1;k<=n;k++)
						if(dis[i][j]!=0x3f3f3f3f&&dis[j][k]!=0x3f3f3f3f){
							if((dis[i][j]+dis[j][k])<dis[i][k]){
								dis[i][k]=(dis[i][j]+dis[j][k]);
								dis[k][i]=(dis[i][j]+dis[j][k]);
								cn[i][k]=1;
								cn[k][i]=1;
							}
							else if((dis[i][j]+dis[j][k])==dis[i][k]){
								cn[k][i]++;
								cn[i][k]++;
							}
						}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(cn[i][j]==2){
						cnt++;
					}
					//cout<<cn[i][j]<<' ';
				}
				//cout<<'\n';
			}
			cout<<cnt/2<<'\n';
		}
		return 0;
	}
	while(t--){
		scanf("%lld %lld",&n,&d);
		ll b,c,e;
		scanf("%lld %lld",&b,&c);
		for(int i=3;i<=n;i++) scanf("%lld",&e);
		if((c-b)<d) cout<<"0\n";
		else{
			d/=(c-b);
			cout<<min(n-d*2+1,0ll)<<'\n';
		}
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
