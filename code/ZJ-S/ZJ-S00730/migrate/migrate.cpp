#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,x[2000005];
long long w[5005][5005][2];
int main(){
//	freopen("migrate4.in","r",stdin);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		if(c==11||c==12){
			long long Dist=x[2]-x[1];
			long long Div=min(d,x[n]-x[1])/Dist;
			if(Div<=1) printf("0\n");
			else printf("%lld\n",max((long long)0,n-Div*2+1));
		}else{
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					w[i][j][1]=i==j?1:0;
				}
			}
			for(int f=1;f<=n;f++){
				for(int i=1;i<=n;i++){
					for(int j=i+1;j<=n&&x[j]-x[i]<=d;j++){
						if(w[f][j][0]>w[f][i][0]+1){
							w[f][j][0]=w[f][i][0]+1;
							w[f][j][1]=w[f][i][1];
						}else if(w[f][j][0]==w[f][i][0]+1){
							w[f][j][1]+=w[f][i][1];
						}
					}
				}
			}
			for(int f=1;f<=n;f++){
				for(int i=0;i<=n;i++){
					if(w[f][i][1]==2) ans+=1;
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
