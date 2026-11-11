#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i) 
#define per(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll read(){ll x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}return x*f;}
ll a[N],m;int n;
void solve1(){
	int ans=0;
	rep(i,2,n){
		ll sum=0;int cnt=1;
		per(j,i-1,1){
			sum+=a[i]-a[j];
			if(sum<=m) cnt++;
			else break;
		}
		ans=max(cnt,ans);
	}
	cout<<ans<<"\n";
}
ll dp[N];
void solve2(){
	dp[1]=0;
	rep(i,2,n){
		dp[i]=dp[i-1]+(a[i]-a[i-1])*(i-1);
		if(dp[i]>m){
			cout<<i-1<<"\n";
			return ;
		}	
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	rep(i,1,n) a[i]=read();
	sort(a+1,a+n+1);
	if(n>5000)solve2();
	else solve1();
	return 0;
} 
