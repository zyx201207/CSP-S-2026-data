#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ll sum=0;
		for(int j=1;j<=i;j++){
			sum+=abs(a[i]-a[j]);
		}
		if(sum>m){
			cout<<i-1;
			return 0;
		}
	}
	
	return 0;
} 
