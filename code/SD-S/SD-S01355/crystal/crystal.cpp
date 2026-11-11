#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<queue>
#include<stack>
#include<cstring>
using namespace std;
const int N=5e5+10;
long long n,a[N],m,pre[N],ans;
bool check(long long x){
	for(int i=x;i<=n;i++){
		if(1ll*a[i]*(x-1)-(pre[i-1]-pre[i-x])<=m)return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	pre[0]=0;
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	long long l=1,r=n;
	while(r>=l){
		long long mid=l+r>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans<<'\n';
	return 0;
} 
