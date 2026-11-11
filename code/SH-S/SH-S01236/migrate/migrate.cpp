#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define N 2000010
#define M 310
#define _for(i,u,v) for(int i=(u);i<=(v);i++)
#define for_(i,u,v) for(int i=(u);i>=(v);i--)
ll a[N]; int n; ll d;
int pl[N];
void solve1(){
	scanf("%d%lld",&n,&d);
	_for(i,1,n) scanf("%lld",&a[i]);
	if(n==1){ printf("0\n"); return; }
	ll sum=d/(a[2]-a[1]);
	if(sum<=1){ printf("0\n"); return; }
	printf("%lld\n",max(0ll,n-sum*2+1));
}
void solve2(){
	scanf("%d%lld",&n,&d);
	_for(i,1,n) scanf("%lld",&a[i]);
	a[n+1]=3e18;
	int x=0,s=0; ll ans=0;
	_for(i,1,n){
		if(a[i]-a[1]<=d&&a[n]-a[i]<=d) x=i,s++;
	} if(s>=3){ printf("0\n"); return; }
	_for(i,1,n){
		pl[i]=upper_bound(a+1,a+n+2,a[i]+d)-a-1;
	} _for(i,1,n){
		if(pl[i]>x) break;
		ans+=pl[pl[i]-1]-pl[pl[i]-2];
	} printf("%lld\n",ans);
	return;
}
ll dp[M][M];
void solve3(){
	scanf("%d%lld",&n,&d);
	_for(i,1,n) scanf("%lld",&a[i]);
	int ans=0;
	_for(date,1,n-3){
		memset(dp,0,sizeof(dp)); dp[date][0]=1;
		_for(i,date,n){
			_for(j,i+1,n){
				if(a[j]-a[i]>d) break;
				_for(k,1,j-1){
					dp[j][k]+=dp[i][k-1];
				}
			}
		} _for(i,date,n){
			_for(k,0,i-1){
				if(dp[i][k]>0){
					if(dp[i][k]==2) ans++;
					break;
				} 
			}
		}  
	} printf("%d\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=0,t; scanf("%d%d",&c,&t);
	if(c==11||c==12){ while(t--) solve1();	}
	if(c==13||c==14){ while(t--) solve2();  } 
	if(c<=6&&c>=1) { while(t--) solve3();  } 
	return 0;
}

