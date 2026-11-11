#include<bits/stdc++.h>
#define ll long long
using namespace std;//Oct31==Dec25?
const int N=5e5+5;
ll a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;ll m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int ans=1;
	for(int i=2;i<=n;i++){
		int l=1,r=i-1,num=i;
		while(l<=r){
			int mid=l+r>>1;
			if(a[i]*(i-mid-1+1ll)-(s[i-1]-s[mid-1])<=m){
				r=mid-1,num=mid;
			}else l=mid+1;
		}
		ans=max(ans,i-num+1);
	}
	cout<<ans;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/ 
/* 
为了避免我眼瞎，先把细节说了，至多m次+1操作

那么我们首先将数组排序是显然的

那这不就糖体吗》我们对于每个数作为最后一个被选中的水晶

前面最多能有多小二分即可 
*/
