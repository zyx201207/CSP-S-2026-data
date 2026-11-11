#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;

int c,t;
int n,d;
int x[N];

int read(){
	int f=1,K=0,C=getchar();
	for(;!isdigit(C);C=getchar())if(C=='-')f=-1;
	for(;isdigit(C);C=getchar())K=K*10+(C^48);
	return f*K;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	scanf("%lld%lld",&c,&t);
	c=read();t=read();
	while(t--){
//		scanf("%lld%lld",&n,&d);
		n=read();d=read();
		int flag=1;
		for(int i=1;i<=n;i++){
//			scanf("%lld",&x[i]);
			x[i]=read();
			if(i>=3&&x[i]-x[i-1]!=x[i-1]-x[i-2])flag=0;
		}
		if(n<=3){
			printf("0\n");
			continue;
		}
		if(flag){
			int num=x[2]-x[1];
//			cout<<num<<" "<<d<<" "<<n<<endl;
			int k=d/num;
			int ans=n-k-k+1;
			if(ans<0)ans=0;
			if(ans>=n-2)ans=0;
			printf("%lld\n",ans);
			continue;
		}
		
		
		
	}
	
	
	return 0;
}
