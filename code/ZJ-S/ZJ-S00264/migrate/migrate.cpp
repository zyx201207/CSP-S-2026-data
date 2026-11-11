#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2000010;
int a[maxn],d[maxn],quni[maxn],huni[maxn];
bool uni[maxn];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		int n,dd,ans=0;
		cin>>n>>dd;
		//if(n==1){cout<<0<<endl;continue;}
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	//	for(int i=2;i<=n;i++) d[i-1]=a[i]-a[i-1];
		if(c==11||c==12){
			int t=dd/d[1];
			if(t==0){
				cout<<0<<endl;
				continue;
			}
			//for(int i=2;i<=(n/t);i++) ans+=(n-i*t+1);
			cout<<ans<<endl; 
			//if(n%t==0) 
		}
		/*
		uni[1]=uni[n]=1;
		for(int i=2;i<=n-1;i++) if(d[i+1]-d[i-1]>dd) uni[i]=1;
		for(int i=1;i<=n;i++) if(uni[i]) quni[i]=quni[i-1]+1; else quni[i]=0;
		for(int i=n;i>=1;i--) if(uni[i]) huni[i]=huni[i+1]+1; else huni[i]=0;
		*///ans+=(quni[i-1]+1)*(huni[i+4]+1);
		//for(int i=1;i<=n-3;i++) 
		//	if(d[i]+d[i+1]+d[i+2]>dd&&d[i]+d[i+1]<=dd&&d[i+1]+d[i+2]<=dd) 
		//		
		//	else 
		//cout<<ans<<endl;
	}
	return 0;
}

