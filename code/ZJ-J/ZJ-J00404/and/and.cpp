#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long sum[100002]={0},n,m,a[100002],ma=INT_MIN;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){	
		for(int j=i+1;j<=n;j++){
			ma=max(a[j]&a[i],ma);
		}
	}
	cout<<ma;
	return 0;
}