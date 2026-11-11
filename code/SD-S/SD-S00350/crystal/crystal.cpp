#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
#define ll long long
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define rop(i,a,b) for(int i=(a);i<(b);++i)
int iread(){int x=0,y=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-') y=-1;c=getchar();}while('0'<=c&&c<='9'){x=(x<<3)+(x<<1)+(c^'0');c=getchar();}return x*y;}
ll lread(){ll x=0,y=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-') y=-1;c=getchar();}while('0'<=c&&c<='9'){x=(x<<3)+(x<<1)+(c^'0');c=getchar();}return x*y;}
const int N=5e5+5;
ll n,m;
ll a[N];
ll s[N];
ll las;
bool pan(int x,int rr){
	ll sum=s[rr]-s[x-1];
	ll len=rr-x+1;
	ll dt=a[rr]*len-sum;
	return dt<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=lread();
	m=lread();
	FOR(i,1,n) a[i]=lread();
	sort(a+1,a+n+1);
	FOR(i,1,n) s[i]=s[i-1]+a[i];
	int an=1;
	FOR(i,2,n){
		las=a[i];
		int l=1,r=i-1;
		int ans=1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(pan(mid,i)){
				ans=max(ans,i-mid+1);
				r=mid-1;
			}
			else {
				l=mid+1;
			}
		}
		an=max(an,ans);
	}
	printf("%d",an);
	return 0;
}

