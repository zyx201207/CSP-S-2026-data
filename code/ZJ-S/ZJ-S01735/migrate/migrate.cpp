#include<bits/stdc++.h>
using namespace std;
long long g[2000009];
int dist[2000009];
int q[2000009],hh=0,tt=-1;
int sum[2000009];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	scanf("%d%d",&c,&T);
	while(T--){
		int n;
		long long d;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",g+i);
		}
		int ans=0;
		for(int k=1;k<=n;k++){
			hh=0;tt=-1;
			q[++tt]=k;
			dist[k]=0;
			sum[k]=1;
			for(int i=k+1;i<=n;i++){
				while(hh<=tt&&g[i]-g[q[hh]]>d)hh++;
				if(hh<=tt)dist[i]=dist[q[hh]]+1;
				else break;
				sum[i]=sum[q[hh]];
				for(int j=1;hh+j<=tt;j++){
					if(dist[q[hh+j]]==dist[q[hh]])sum[i]+=sum[q[hh+j]];
					else break;
				}
				
				if(sum[i]==2)ans++;
				while(hh<=tt&&dist[q[tt]]>dist[i])tt--;
				q[++tt]=i;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
