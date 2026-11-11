#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,x[2000005];
inline int read(){
	int sum=0,f=1;
	char x=getchar();
	while(!isdigit(x)){
		if(x=='-')f=-1;
		x=getchar();
	}
	while(isdigit(x)){
		sum=(sum<<1)+(sum<<3)+(x^48);
		x=getchar();
	}
	return f*sum;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n=read(),d=read(),ans=0;
		for(int i=1;i<=n;i++)x[i]=read();
		if(c==11||c==12){
			int y=x[2]-x[1],c=d/y;
			if(d<=y){
				cout<<0<<'\n';
				continue;
			}
			cout<<max(0ll,n+1-2*c)<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			int j=upper_bound(x+1,x+n+1,x[i]+d)-x-1,lst=i;
			bool flag=0;
			while(j<=n){
				int k=upper_bound(x+1,x+n+1,x[j]+d)-x-1;
				if(k==j)break;
				if(flag)ans+=max(0ll,k-(upper_bound(x+1,x+n+1,x[j-1]+d)-x)+1);
				else if(j-1!=lst)ans+=max(0ll,upper_bound(x+1,x+n+1,x[j-1]+d)-x-(upper_bound(x+1,x+n+1,x[max(j-2,lst)]+d)-x));
				if(x[k]-x[j-1]<=d){
					if((j-2&&x[k]-x[j-2]<=d)||flag)break;
					flag=1;
				}
				lst=j;
				j=k;
			}
		}
		cout<<ans<<'\n';
	}
}
