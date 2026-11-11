#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,num,a[1000005],ans;
	cin>>n>>num;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	ans=a[n];
	for(long long i=1;i<=num-1;i++){
		ans&=a[n-i];
	}cout<<ans;
	
	return 0;
}
