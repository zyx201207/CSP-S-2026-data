#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		sum+=(a[i]-a[i-1])*(i-1);
		if(sum>m){
			cout<<i-1;
			return 0;
		}
	}
	return 0;
}
