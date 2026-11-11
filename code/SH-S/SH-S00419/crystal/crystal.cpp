#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m; 
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int sum=0; 
	for(int i=1;i<=n;i++){
		sum+=(i-1)*(a[i]-a[i-1]);
		if(sum>m){
			cout<<i-1;
			break;
		}
	}
	return 0;
}
