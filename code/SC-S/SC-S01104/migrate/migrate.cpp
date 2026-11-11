#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n,cnt;
long long d,x[N],minx,ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
			minx=min(minx,x[i]-x[i-1]);
		}
		if(minx>d){
			printf("%d\n",0);
			continue;
		}
		if(c>=13&&c<=14){
			ans=0;
			for(int i=1;i<=n/2+1;i++){
				for(int j=n;j>=i;j--){
					if(x[j]-x[i]>d) ans++;
					else break;
				}
			}
			printf("%lld\n",ans);
		}
		else if(c>=1&&c<=6){
			ans=0;
			for(int i=1;i<=n-3;i++){
				for(int j=i+3;j<=n;j++){
					if(x[j]-x[i]<=d) continue;
					cnt=0;
					for(int k=i+1;k<j;k++){
						if(x[k]-x[i]<=d&&x[j]-x[k]<=d) cnt++;
					}
					if(cnt==2){
						ans++;
					}
				}
			}
			printf("%lld\n",ans);
		}
		else{
			printf("%d\n",0);
		}
	}
	return 0;
}
/*0 2
10 3
-100 -97 -94 -93 -92 -91 -90 -89 -86 -83*/