#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],pre[500005];
bool check(int mid){
	for(int i=1;i<=n-mid+1;i++){
		if(a[i+mid-1]*(mid-1)-(pre[i+mid-2]-pre[i-1])<=m){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];	
	}
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
} 
