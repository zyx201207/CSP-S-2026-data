#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t,n;
ll d,x[2000005];
ll fa1[2000005],fa2[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		ll ans=0;
		x[0]=-2e18;x[n+1]=2e18;
		for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
		for(int i=1;i<=n;i++)fa1[i]=fa2[i]=i;
		for(int i=1;i<=n;i++){
			int y=0;
			while(x[i]+d>=x[i+y+100]&&i+y+100<=n)y+=100;
			while(x[i]+d>=x[i+y+1]&&i+y+1<=n)y++;
			if(y)fa1[i]=i+y;
			y=0;
			while(x[i]-d<=x[i-y-100]&&i-y-100>=1)y+=100;
			while(x[i]-d<=x[i-y-1]&&i-y-1>=1)y++;
			if(y)fa2[i]=i-y;
		}
		
		//for(int i=1;i<=n;i++)printf("%lld ",fa1[i]);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int y[200005]={},m=i,tt=0;
				y[0]=i;
				while(fa1[m]<j&&fa1[m]!=m)m=fa1[m],y[++tt]=m;
				if(m==j||tt==0)continue;
				int p=fa2[j];
				if(p+1==y[tt]){
					if(p<=fa1[i]||fa2[p]==y[tt-1])ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
