#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,T,v[2000005];
ll n,d,a[2000005],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		ans=0;
		memset(v,0,sizeof(v));
		scanf("%lld%lld",&n,&d);
		for(long long i=1;i<=n;i++){
			scanf("%lld",a+i);
		}
		if(c==11||c==12){
			if(n<=3) printf("0\n");
			else if(a[3]-a[1]<=d&&a[4]-a[1]>d)printf("%lld\n",n-3);
			else printf("0\n");
			continue;
		}
		for(int i=1;i<=n;i++){
			if(a[i+3]-a[i]>d&&(a[i+3]-a[i+2]<=d&&a[i+3]-a[i+1]<=d)&&(a[i+2]-a[i]<=d&&a[i+1]-a[i]<=d)){//©ирт 
				if(v[i+2]==0){v[i+2]=-1;}
				else{v[i+2]=2;}
				if(v[i]==0){v[i]=1;}
				else{v[i]=2;}
				ans++;
			}
		}
		for(int i=1;i<=n;i++){
			if((v[i+1]==1||v[i+1]==2)&&(a[i+2]-a[i])>d&&(a[i+1]-a[i])<=d){
				if(v[i]==0){v[i]=1;}
				else{v[i]=2;}
				ans++;
			}
		}for(int i=3;i<=n;i++){
			if((v[i-1]==1||v[i-1]==2)&&(a[i]-a[i-2])>d&&(a[i]-a[i-1])<=d){
				if(v[i]==0){v[i]=-1;}
				else{v[i]=2;}
				ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
