#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=5e5+10;
int n;
ll m,a[MAXN];
bool check(int x){
	ll cnt=0;
	for(int i=1;i<x;i++)cnt+=a[x]-a[i];
	if(cnt<=m)return 1;
	for(int i=x+1;i<=n;i++){
		cnt=cnt+(x-1)*(a[i]-a[i-1])-a[i-1]+a[i-x];
		if(cnt<=m)return 1;	
	}return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	cout<<ans;
	return 0;
}
