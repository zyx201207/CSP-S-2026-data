#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
int n,m;
ll a[500005],dp[500005];
bool cmp(ll x,ll y){
	return x>y;
}

bool check(int x,int h,int st){
	int s=(x-st+1)*h-(dp[x]-dp[st-1]);
	if(s<=m)return 1;
	else return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1]+a[i];
	}
	int maxans=0;
	int nowx=1;
	for(int j=1;j<=n;j++){
		int i=a[j];
		int cnt=0;
		int l=j,r=n;
		while(l<r){
			int mid=(l+r+1)/2;
//			cout<<mid<<" "<<i<<" "<<j<<"\n";
			if(check(mid,i,j)){
//				cout<<"          "<<mid<<" "<<i<<" "<<j<<"\n";
				cnt=mid;
				l=mid;
			}
			else r=mid-1;
		}
		maxans=max(maxans,cnt-j+1);
	}
	cout<<maxans;
	return 0;
}
