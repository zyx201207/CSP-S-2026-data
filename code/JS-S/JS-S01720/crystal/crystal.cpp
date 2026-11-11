#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
long long s[500005];
bool check(int x){
	for(int i=x;i<=n;i++){
		if(a[x]*x-s[x]<=m){
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
		s[i]=a[i]+s[i-1];
	}
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<l-1;
	return 0;
}
