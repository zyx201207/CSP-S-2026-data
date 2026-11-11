#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,mid,ans=-1;
	int a[500002];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	mid=n/2+1;
	if(abs(abs(a[0])-a[mid])>=abs(abs(a[n-1])-a[mid])){
		for(int i=0;i<abs(n-1-mid);i++){
			ans+=abs(a[mid]-a[i]);
		}
		cout<<ans-mid;
	}else{
		for(int i=0;i<mid;i++){
			ans+=abs(a[mid]-a[i]);
		}
		cout<<ans-mid;
	}
	return 0;
}