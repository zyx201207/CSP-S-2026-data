#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int a[N],n,m;
bool check(int x){
	int sum=0;
	for(int i=1;i<x;i++){
		sum+=a[x]-a[i];
	}int mn=sum;
	for(int i=x+1;i<=n;i++){
		sum+=(x-1)*(a[i]-a[i-1]);
		sum-=a[i-1]-a[i-x];
		mn=min(mn,sum);
	}if(mn<=m)return 1;
	else return 0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int l=0,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			ans=mid,l=mid+1;
		}else r=mid-1;
	}cout<<ans;
	return 0;
}