#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m; 
ll a[500010];
ll pre[500010];


bool cmp(ll a,ll b){
	return a<b;
}

bool check(int k){
	if (k==1) return true;
	else if (((k-1)*a[k])-(pre[k-1])<=m){
		return true;
	}	
	return false;
	
	
} 


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	pre[1]=a[1];
	for (int i=2;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	int left=1;
	int right=n;
	int ans=1;
	while (left<=right){
		int mid=(right+left)/2;
		if (check(mid)){
			ans=mid;
			left=mid+1;
		}
		else{
			right=mid-1;
		}
	}
	cout<<ans;
	return 0;
	
}
