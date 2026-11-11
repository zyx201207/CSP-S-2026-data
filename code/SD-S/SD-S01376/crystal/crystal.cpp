#include<bits/stdc++.h>
#define int long long
#define MAXN 500005
using namespace std;

inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}

int n,m;
int res1,res2;
int a[MAXN];
int pre[MAXN];
int suf[MAXN];
int dis[MAXN];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
//	int ave=0,ret=0;
	for(int i=1;i<=n;i++){
		a[i]=read();
//		ave+=a[i];
//		ret+=ave/n;
//		ave=ave%n;
	}
//	ave/=n;
//	cout<<ret<<"\n";
//	for(int i=1;i<=n;i++){
//		a[i]-=ret;
//		a[i]=abs(a[i]);
//	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		dis[i]=a[i]-a[i-1];
		pre[i]=pre[i-1]+dis[i]*(i-1);
	}
	for(int i=n-1;i>=1;i--){
		dis[i]=a[i+1]-a[i];
		suf[i]=suf[i+1]+dis[i]*(i-1);
	}
	for(int i=1;i<=n;i++){
		if(m<pre[i]){
			res1=i-1;
			break;
		}
	}
	for(int i=n;i>=1;i--){
		if(m<suf[i]){
			res2=n-i+1;
			break;
		}
	}
	printf("%lld\n",max(res1,res2));
//	int sum=0;
//	for(int i=1;i<=n;i++){
//		sum+=a[i];
//		if(sum>m){
//			printf("%lld\n",i-1);
//			break;
//		}
//	}
	return 0;
} 
/*
5 3
1 3 4 5 9
63 52
3 4 8 6 4 3 9 6 1 4 6 4 3 6 3 4 4 2 8 6 6 4 3 6 3 4 9 6 9 9 3 4 4 2 8 6 6 4 3 6 6 9 6 8 2 3 8 6 9 9 6 5 8 4 4 8 6 8 2 4 8 6
*/
