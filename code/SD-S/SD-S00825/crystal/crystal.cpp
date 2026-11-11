#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PQ priority_queue
#define ump unordered_map
#define inf 0x3f3f3f3f
#define mod 998244353
using namespace std;
const int N=5e5+10;
int n;
ll a[N],m,sum[N];
bool check(int x){
	for(int i=x;i<=n;i++){
		if(m>=a[i]*x-(sum[i]-sum[i-x])) return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int l=1,r=n;
	while(l<r){
		int mid=l+r+1>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	printf("%d",r);
	
	
	return 0;
} 
