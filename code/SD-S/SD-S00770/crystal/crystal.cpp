#include<bits/stdc++.h>
#define int long long 
#define N 1145140
#define pii std::pair<int,int>
#define elif else if
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	} 
	while('0'<=c&&c<='9'){
		s=s*10+(c-'0');
		c=getchar();
	}
	return s*f; 
}
int n,m;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	std::sort(a+1,a+1+n);
	int ans=1,sum=0;
	for(int i=2,j=1;i<=n;++i){
		sum+=(a[i]-a[i-1])*(i-j);
//		printf("(%lld,%lld,%lld)\n",i,j,sum);
		while(sum>m&&j<i){
			sum-=(a[i]-a[j]);++j;
		}
		ans=std::max(i-j+1,ans);
	}
	printf("%lld",ans);
	return 0;
} 
//14:45
//我想在这里写个歌词的，但是没力气了 
