#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d;
long long a[2000010];
long long dd[15][15][2];
inline void dfs(int x,int y,long long z,int cc){
	if(cc==y){
		if(z==dd[x][y][0])
		    dd[x][y][1]++;
		if(z<dd[x][y][0])
		    dd[x][y][0]=z,dd[x][y][1]=1;
		return;
	}
	if(cc>=n)
	    return;
	for(int i=cc+1;i<=n;i++)
	    if(a[i]-a[cc]<=d)
	        dfs(x,y,z+1,i);
	    else 
	        break;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)
		    scanf("%lld",&a[i]);
		if(n<=3){
			puts("0");
			continue;
		}
		bool ok=true;
		long long c=a[2]-a[1];
		for(int i=2;i<n;i++)
		    if(a[i+1]-a[i]!=c)
		        ok=false;
		if(ok==true){
			if(d<2*c){
				puts("0");
				continue;
			}
			long long e=d/c;
			printf("%lld\n",max(0LL,n-2*e+1));
			continue;
		}
		if(n<=9){
			for(int i=1;i<=n;i++)
			    for(int j=i+1;j<=n;j++)
			        dd[i][j][0]=1e18,dd[i][j][1]=-1;
			for(int i=1;i<=n;i++)
			    for(int j=1;j<=n;j++)
			        dfs(i,j,0,i);
			long long ans=0;
			for(int i=1;i<=n;i++)
			    for(int j=1;j<=n;j++)
			        if(dd[i][j][1]==2)
			            ans++;
			printf("%lld\n",ans);
			continue;
		}
		printf("0\n");
	}
	return 0;
}
