// Why this year is so easy???????????????????????????
//666开智了有中文输入法，感觉4题都很简单，但是T3挂飞了,T4式子不会推，我的人生无疑是失败的。
//我无疑是愤怒的 
//
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N];
int sum[N];
int up;
int n,m;
bool check(int x){
	int res=(up-x+1)*a[up]-(sum[up]-sum[x-1]);
	return res<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]+=sum[i-1];
		sum[i]+=a[i];
	}
	int now=0;
	int ans=1;
	for(int i=2;i<=n;i++){
		int l=1,r=i;
		int mid;
		int fd=r;
		up=i;
		while(l<=r){
			mid=(l+r)>>1;
			if(check(mid)){
				fd=mid;
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		ans=max(ans,i-fd+1);
	}
	cout<<ans<<'\n';
	return 0;
}
/*
5 5
1 2 4 8 9
*/
