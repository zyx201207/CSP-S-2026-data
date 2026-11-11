#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,minn,p,cmin,tot,a[2000006],dis[3500][3500],w[2000006],q[10000],f,r;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		tot=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(int j=1;j<=n;j++){
			f=r=0;
			for(int i=j-1;i>=1;i--){
				
				while(a[q[f+1]]-a[i]>d&&f<r) f++;
				if(a[j]-a[i]>d&&f<r) break;
				if(a[j]-a[i]<=d) dis[i][j]=1;
				else dis[i][j]=dis[q[f+1]][j]+1;
				while(dis[q[t]][j]>dis[i][j]&&f<r) r--;
				q[++r]=i;
				p=f;
				while(dis[q[p+1]][j]==dis[q[p+2]][j]&&p+1<r) p++;
				if(p-f+1==2) tot++;
			}
		} 
		printf("%lld\n",tot);
	}
	return 0;
}
