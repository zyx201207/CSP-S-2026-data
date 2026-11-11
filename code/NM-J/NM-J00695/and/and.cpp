#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+1+n);
	long long ans=a[n];
	for(int i=n-1;i>n-m;i--){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
} 
