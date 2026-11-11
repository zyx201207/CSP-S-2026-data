#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+5;
ll n,m,a[N],S[N];
ll ans,l,r,mid;
bool check(int x,int y){//能否使得a[y-x]--a[y-1]全部变成a[y]
	if(a[y]*x-(S[y-1]-S[y-x-1])<=m) return 1;
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	S[0] = 0;
	for(int i = 1;i<=n;i++) S[i] = S[i-1]+a[i];
	ans = 0;
	for(int i = 1;i<=n;i++){//选择一个数作为基准
		l = 0;
		r = i-1;
		while(l<=r){
			mid = (l+r)/2;
			if(check(mid,i)){
				ans = max(ans,mid+1);
				l = mid+1;
			}
			else r = mid-1;
		}
	}
	cout<<ans;
	return 0;
}