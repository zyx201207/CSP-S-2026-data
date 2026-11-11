#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long m;
	int n;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long ans=0;
	for(int i=2;i<=n;i++){
		ans+=(a[i]-a[i-1])*(i-1);
		if(ans>m){
			cout<<i-1;
			return 0;
		}
	}
	
	return 0;
}
