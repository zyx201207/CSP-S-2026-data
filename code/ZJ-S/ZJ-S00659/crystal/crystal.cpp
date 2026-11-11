#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal4.in", "r",stdin);
	freopen("crystal4.out", "w",stdout);
	int n;
	long long m;
	cin>>n;
	cin>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ma=0;
	for(int i=1;i<=n-ma;i++){
		cout<<1;
		long long x=0;
		int j=i+1;
		for(;j<=n;j++){
			x+=((long long)j-1)*(a[j]-a[j-1]);
			if(x>m){
				break;
			}
		}
		if(ma<=j-i){
			ma=j-i;
		}
	}
	cout<<ma;
	return 0;
}
