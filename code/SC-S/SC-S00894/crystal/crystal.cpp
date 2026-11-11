#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
int n,m;
int check(int mid){
	int t=m,cnt=0;
	for(int i=n;i>=1;i--){
		if(a[i]<=mid){
			if(t-mid+a[i]<0)break;
			t-=mid-a[i];
			cnt++;
		}
	}
	return cnt;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n<=5000){
	int l=a[1],r=a[n],ans=-1;
	for(int i=1;i<=n;i++){
		int k=check(a[i]);
		if(k>ans)ans=k;
	}
	cout<<ans;
	}else{
		cout<<check(a[n]);
	}
	return 0;
}