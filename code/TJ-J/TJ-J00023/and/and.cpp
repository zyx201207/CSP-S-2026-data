#include <bits/stdc++.h>

using namespace std;

#define int long long
int n,m,sum;
int a[20005] 
signed main(){
	freopen("and.in","r",stdin);
	cin>>m,n;
	for(int i=0;i<=n;i++){
		cin>>a[i];
		if(a[i]%a[i-1]!=0){
			sum=a[i];
		}
	}
	cout<<sum;
	freopen("and.out","W",stdout);
	return 0;

}
