#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	/*int maxx=0;
	for(int i=1;i<=n;i++){
		int sum=0;
		int j=i;
		while(sum<=m&&j<n){
			while(a[j+1]==a[j]){
				j++;
			}
			sum+=(j-i+1)*(a[j+1]-a[j]);
			j++;
			if(sum>m){
				j--;
			}
		}
		maxx=max(maxx,j-i+1);
	}
	cout<<maxx;*/
	ll l,r;
	ll minn=LLONG_MAX;
	for(ll i=1;i<n;i++){
		if(a[i+1]-a[i]<minn){
			minn=a[i+1]-a[i];
			l=i;
			r=i+1;
		}
	}
	ll sum=a[r]-a[l];
	if(sum>m){
		cout<<1;
		return 0;
	}
	while(1){
		while(l>1&&a[l]==a[l-1]){
			l--;
		}
		while(r<n&&a[r]==a[r+1]){
			r++;
		}
		if(l>1&&r<n&&a[r]-a[l-1]<(a[r+1]-a[r])*(r-l+1)){
			sum+=a[r]-a[l-1];
			l--;
		}else if(l>1&&r<n&&a[r]-a[l-1]>=(a[r+1]-a[r])*(r-l+1)){
			sum+=(a[r+1]-a[r])*(r-l+1);
			r++;
		}else if(l==1&&r<n){
			sum+=(a[r+1]-a[r])*(r-l+1);
			r++;
		}else if(l>1&&r<=n){
			sum+=a[r]-a[l-1];
			l--;
		}else{
			break;
		}
		if(sum>m){
			r--;
			break;
		}else if(sum==m){
			break;
		}
		//a[r]-a[l-1]
		//if()
		//(a[r+1]-a[r])*(r-l+1)
	}
	cout<<r-l+1;
	return 0;
}
