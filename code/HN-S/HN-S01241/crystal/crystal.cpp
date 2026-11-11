#include<bits/stdc++.h>
using namespace std;
int a[500010];
int pre[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long ans=1,n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++){
		pre[i]=a[i];
		if(i>0) pre[i]+=pre[i-1];
	}
	int cnt=0;
	for(long long i=1;i<n;i++){
		long long sum=a[i]*i-pre[i-1];
		if(sum>m) break;
		ans=i+1;
	}
	cout<<ans;
	return 0; 
} 

