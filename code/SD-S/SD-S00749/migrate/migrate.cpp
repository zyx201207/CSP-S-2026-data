#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	char c=getchar();
	long long x=0,f=1;
	while(c>'9'||c<'0'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
inline void write(long long x){
	if(x<0){
		putchar('-');
		write(-x);
		return ;
	}
	if(x>9){
		write(x/10);
	}
	putchar(x%10+'0');
	return ;
}
const int N=2e6+5;
const int INF=1e9+7;
int C,T,n,line;
long long d,a[N];
int pre[N],suf[N];
int cnt[N];
long long dp[N],c[N],s[N];
long long ans;
int lowbit(int x){
	return x&-x;
}
void update(int x,int k){
	for(int i=x;i<=n;i+=lowbit(i)){
		c[i]+=k;
	}
	return ;
}
long long fun(int x){
	long long res=0;
	for(int i=x;i;i-=lowbit(i)){
		res+=c[i];
	}
	return res;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	C=read(),T=read();
	while(T--){
		n=read(),d=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
			s[i]=0,dp[i]=0,c[i]=0;
		}
		line=1;
		for(int i=1;i<=n;i++){
			while(a[line]+d<a[i]){
				line++;
			}
			pre[i]=line;
		}
		line=n;
		for(int i=n;i>=1;i--){
			while(a[i]+d<a[line]){
				line--;
			}
			suf[i]=line;
		}
		for(int i=1;i<=n;i++){
			cnt[i]=1;
			if(suf[i-1]==i){
				cnt[i]+=cnt[i-1];
			}
		}
		ans=0;
		for(int i=1;i<=n;i++){
			int t=pre[i];
			s[i]=s[i-1];
			if(pre[t]==t){
				update(suf[i],cnt[i]);
				continue;
			}
			dp[i]+=s[i-1]-s[t-1];
			ans=ans+dp[i];
			s[i]+=dp[i];
			if(t==i-1){
				update(suf[i],cnt[i]);
				continue;
			}
			long long k=fun(t+1)-fun(t); 
			ans+=k;
			if(suf[i-1]>i){
				update(suf[i],cnt[i]);
				continue;
			}
			update(suf[i],cnt[i]);
			dp[i]+=k;
			s[i]+=k;
		}
		write(ans);
		putchar('\n');
	}
	return 0;
} 
