#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int N=1e6+10,MOD=1e9+7;
int n,m,a[N],ans,num[N];
bool check(int x){
	int need,sum;
	for(int i=1;i<=n-x+1;i++){
		need=x*(a[x+i-1]);
		sum=num[i+x-1]-num[i-1];
		if(sum+m-need>=0){
			return 1;
		}
	}
	return 0;
}
signed main(){
	IOS
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		num[i]=num[i-1]+a[i];
	}
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=max(ans,mid);
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
