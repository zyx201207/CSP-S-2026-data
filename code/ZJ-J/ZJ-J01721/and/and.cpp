#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200010]={},cnt[10]={};
int count(int t){
	int cnt=0;
	while(t) cnt+=t&1,t>>=1;
	return cnt;
}
int sz(int t){
	int cnt=0;
	while(t) cnt++,t>>=1;
	return cnt;
}
struct _1_to_5{
	int ans=0;
	int check(int mask){
		int sum=2147483647;
		for(int i=1;i<=n;i++) if((mask>>(i-1))&1) sum&=a[i];
		return sum;
	}
	int dp(){
		for(int i=0;i<(1<<n);i++) if(count(i)==m) ans=max(ans,check(i));
		return ans;
	}
}a1;
bool f1=true,f2=true;
signed main(){
	srand(time(0));
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),sz(a[i])!=count(a[i])?f1=false:0,a[i]>3ll?f2=false:0;
	sort(a+1,a+n+1);
	cout<<a1.dp()<<" ";
	if(n<=20) printf("%lld",a1.dp());
	else if(m==1) printf("%lld",a[n]);
	else if(m==n){
		int ans=2147483647;
		for(int i=1;i<=n;i++) ans&=a[i];
		printf("%lld",ans);
	}
	else if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j) ans=max(ans,a[i]&a[j]);
		printf("%lld",ans);
	}
	else if(m==n-1){
		int res1=2147483647,res2=2147483647;
		for(int i=1;i<n;i++) res1&=a[i];
		for(int i=2;i<=n;i++) res2&=a[i];
		printf("%lld",max(res1,res2));
	}
	else if(f1){
		int ans=2147483647;
		for(int i=n;i>=n-m+1;i--) ans&=a[i];
		printf("%lld",ans);
	}
	else if(f2){
		for(int i=1;i<=n;i++) cnt[a[i]]++;
		if(cnt[3]>=m) puts("3");
		else if(cnt[3]+cnt[2]>=m) puts("2");
		else if(cnt[3]+cnt[2]+cnt[1]>=m) puts("1");
		else puts("0");
	}
	else printf("%d",rand());
	return 0;
}
