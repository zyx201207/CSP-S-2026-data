#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
long long ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--){
		long long m1=m;
		long long s=1;
		long long r=i-1;
		while(1){
			if(r<1)break;
			if(a[i]-a[r]>m1)break;
			s+=1;
			m1-=a[i]-a[r];
			r--;
		}
		ans=max(ans,s);
	}
	cout<<ans;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/