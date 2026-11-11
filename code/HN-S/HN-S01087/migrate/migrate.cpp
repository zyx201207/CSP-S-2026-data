#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar_unlocked();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar_unlocked();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar_unlocked();
	}
	return x*f;
}
int n,c,t,dis[2000005],sum[2000005],x[2000005],d;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	if(c<=10){
		while(t--){
			n=read(),d=read();
			for(int i=1;i<=n;i++){
				x[i]=read();
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				int l=i,r=i,cnt=1;
				for(int j=i;j<=n;j++){
					dis[j]=sum[j]=0;
				}
				sum[i]=1;
				for(int j=i+1;j<=n;j++){
					while(l<j&&x[j]-x[l]>d) cnt-=sum[l],l++;
					if(l==j) break;
					while(r<j&&dis[r]<=dis[l]) r++,cnt+=sum[r];
					cnt-=sum[r--];
					dis[j]=dis[l]+1;
					sum[j]=cnt;
					ans+=(cnt==2);
				}
			}
			cout<<ans<<"\n";
		}
	}else if(c==11||c==12){
		while(t--){
			n=read(),d=read();
			for(int i=1;i<=n;i++){
				x[i]=read();
			}
			int val=d/(x[2]-x[1]);
			if(val<=1) cout<<"0\n";
			else cout<<max(0ll,n-val*2+1)<<"\n";
		}
	}else{
		while(t--){
			n=read(),d=read();
			for(int i=1;i<=n;i++){
				x[i]=read();
			}
			cout<<"0\n";
		}
	}
	return 0;
}
/*
15 1
4 2
1 2 3 4
5 2
1 2 3 4 5
* 
0 1
4 2
1 2 3 4
*/
