#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=1,r=1,ans=1;
	long long sum=0;
	while(r<n){
		sum+=(r-l+1)*(a[r+1]-a[r]);
		r++;
		if(sum>m){
			sum-=a[r]-a[l];
			l++;
		}
		ans=max(r-l+1,ans);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/