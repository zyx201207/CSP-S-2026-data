#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[1005000];
int s[1005000];
bool check(int len){
	for(int i=1;i+len-1<=n;i++){
		int j=i+len-1;
		int x=s[j]-s[i-1];
		int c=(a[j]*len)-x;
		if(c<=m){
			return 1;
		}
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int l=1,r=n,ans=-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}