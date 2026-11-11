#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int mx=5e5+10;
ll n,m;
ll a[mx];
ll sum[mx],s[mx];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	s[1]=a[1];
	for(int i=2;i<=n;i++){
		s[i]=s[i-1]+a[i]; 
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i,mid;
		while(l<=r){
			int mid=(l+r)/2;
			int tmp=a[i]*(i-mid)-s[i-1]+s[mid-1];
			if(tmp<=m){
				ans=max(ans,i-mid+1);
				r=mid-1;
			}
			else l=mid+1;
		}
		while(mid+1<=n&&a[i]*(i-mid)-s[i-1]+s[mid-1]>m) mid++;
		while(mid-1>=1&&a[i]*(i-mid+1)-s[i-1]+s[mid-2]<=m) mid--;
		ans=max(ans,i-mid+1);
		//cout<<i<<" "<<mid<<endl;
	}
	//for(int i=1;i<=n;i++) cout<<sum[i]<<" ";
	//cout<<sum[315276]<<endl;
	cout<<ans<<endl;
	
	return 0;
} 
