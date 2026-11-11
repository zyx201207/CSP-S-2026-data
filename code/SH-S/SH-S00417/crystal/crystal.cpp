#include<bits/stdc++.h>
using namespace std;
int n;
int cnt;
long long m;
long long a[500009];
long long s[500009];
bool ck(int len){
	for(int i=len;i<=n;i++){
		if(s[i]-s[i-len]+m>=len*a[i]) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int l=1,r=n;
	while(l<r){
		//cout<<l<<" "<<r<<endl;
		int mid=(l+r+1)/2;
		if(ck(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l<<"\n";
	return 0;
}
