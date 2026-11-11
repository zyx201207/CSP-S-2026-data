#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
const int maxn=5e5+10;
ll n,m,a[maxn],s[maxn],ans;
bool check(ll x,ll y){// [x,i-1]
//	cout<<x<<" "<<y<<" "<<y*(y-x+1)<<" "<<(s[y]-s[x-1])<<"\n";
	return a[y]*(y-x+1)-(s[y]-s[x-1])<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++)s[i]=s[i-1]+a[i];
//	for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<"\n";
//	for(int i=1;i<=n;i++)cout<<s[i]<<" ";cout<<"\n";
	for(ll i=1;i<=n;i++){
		ll l=1,r=i;
//		cout<<"<------>\n"<<i<<"\n";
		while(l<r){
			ll mid=l+r>>1;// [mid,i]
			if(check(mid,i))r=mid;
			else l=mid+1;
//			cout<<mid<<" "<<check(mid,i)<<"\n";
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

2:33 有思路，开始写 
2:38 假了 
3:03 通过全部样例 

OS：这个电脑屏幕保护膜上的水印真碍事 

*/
