#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],sum[500010],pos;
bool check(int x){
	queue<int> q;
	int res=sum[x];
	if(res<=m)return 1;
	for(int i=x+1;i<=n;i++){
		res=sum[i]-sum[i-x+1]-(a[i]-a[i-x+1])*(i-x);
		if(res<=m) return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+(a[i]-a[i-1])*(i-1);
	}
	int l=0,r=n;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid)){
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<l;
	return 0;
} 
