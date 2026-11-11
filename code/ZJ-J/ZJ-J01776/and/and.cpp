#include<bits/stdc++.h>
using namespace std;
const int MA=200005;
long long n,m;
long long a[MA],dp[MA][25],maxa,ans;
int sum[32],sum_s;
bool g[MA][31];
bool tp=true;
bool cho[31][MA];
struct data{
	long long da,sum_1;
}gj[MA];
bool cmp(data a,data b)
{
	return a.sum_1>b.sum_1;
}
long long read()
{
	long long f=1,x=0;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return f*x;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		maxa=max(maxa,a[i]);//tp
		if(a[i]!=a[i-1]) tp=false;//tp
		long long x=a[i];
		int now=0;
		while(x){
			now++;
			if(x%2){
				g[i][now]=1;
				sum[now]++;
			}
			x/=2;
		}
	}
	if(n<=20){
		for(int i=1;i<=n;i++){
			dp[i][1]=a[i];
			for(int j=1;j<i;j++){
				for(int k=2;k<=m;k++){
					if(j>=k-1)
					dp[i][k]=max(dp[i][k],dp[j][k-1]&a[i]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			ans=max(ans,dp[i][m]);
		}
		printf("%lld",ans);
		return 0;
	}
	if(m==1){//tp
		printf("%lld",maxa);
		return 0;
	}
	if(m==2&&n<=2000){//tp
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		printf("%lld",ans);
		return 0;
	}
	if(n==m){//tp
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		printf("%lld",ans);
	}
	if(tp){ //tp
		printf("%lld",a[1]);
		return 0;
	}
	int start=31;
	while(sum[start]<m&&start>0){
		start--;
	}
	if(start==0){
		printf("0");
		return 0;
	}
	if(sum[start]==m){
		for(int i=1;i<=n;i++){
			if(g[i][start]&&ans) ans&=a[i];
			else if(g[i][start]) ans=a[i];
		}
		printf("%lld",ans);
		return 0;
	}
	else{
		for(int i=1;i<=start;i++){
			if(sum[i]>m){
				for(int j=1;j<=n;j++){
					if(g[j][i]) cho[i][j]=true;
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(cho[start][i]){
				sum_s++;
				gj[sum_s].da=a[i];
				for(int j=start;j>=1;j--&&g[i][j]){
					gj[sum_s].sum_1++;
				}
			}
		}
		sort(gj+1,gj+sum_s+1,cmp);
		ans=gj[1].da;
		for(int i=2;i<=m;i++){
			ans&=gj[i].da;
		}
		printf("%lld",ans);
	}
}
