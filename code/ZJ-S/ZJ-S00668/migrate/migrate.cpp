#include<bits/stdc++.h>
using namespace std;
long long a[2000010];
bool can[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		memset(can,0,sizeof(can));
		long long n,d,ans=0;
		scanf("%lld%lld",&n,&d);
		for(int i=0;i<n;++i){
			cin>>a[i];
		}
		for(int i=0;i<n-2;++i){
			can[i]=a[i+1]-a[i]<=d && a[i+2]-a[i]>d;
		}
		if(n>1)can[n-2]=a[n-1]-a[n-2]<=d;
		can[n-1]=false;
		for(int i=1;i+2<n;++i){
			if(a[i+1]-a[i-1]<=d && a[i+2]-a[i]<=d && a[i+1]-a[i]<=d && a[i+2]-a[i-1]>d){
				long long cl=1,cr=1;
				while(i-cl-1>=1 && can[i-cl-2])++cl;
				if(i-cl==1 && can[0])++cl;
				while(i+2+cr<n && can[i+1+cr] && can[i+cr])++cr;
				ans+=cl*cr;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}