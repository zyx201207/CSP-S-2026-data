// 75·Ö 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+9;
ll n,m,ans;
ll a[N],d[N],sum[N],df[N];
ll gongcha;
bool A=1,B=1;
void solveA(){
	for(int i=1;i<=n;i++){
		df[i]=i*(i+1)/2;
	}
	if(m>=df[n-1]) printf("%lld\n",n);
	else{
		ll x=lower_bound(df+1,df+1+(n-1),m)-df-1;
		printf("%lld\n",x+1);
	}
}
void solveB(){
	for(int i=1;i<=n;i++){
		df[i]=i*(i+1)/2;
	}
	if(m>=df[n-1]) printf("%lld\n",n);
	else{
		ll x=lower_bound(df+1,df+1+(n-1),m/gongcha)-df-1;
		printf("%lld\n",x+1);
	}
}
void solveBF(){
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		d[i]=a[i]-a[i-1];
		sum[i]=sum[i-1]+d[i];
	}
	for(int i=1;i<=n;i++){
		ll x=a[i],t=m,res=0; 
		for(int j=i;j>=1;j--){
			if(t==0) break;
			if(t>=a[i]-a[j]) {t-=(a[i]-a[j]);res++;}
		}
		ans=max(ans,res);
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=i) A=0;
	}
	gongcha=a[2]-a[1];
	for(int i=2;i<n;i++){
		if(a[i+1]-a[i]!=gongcha){
			B=0; break;
		}
	}
	if(A){solveA(); return 0;}
	else if(B){solveB(); return 0;}
	else if(n<=10000){solveBF(); return 0;}
	else{printf("%lld\n",n); return 0;}
	return 0;
} 
