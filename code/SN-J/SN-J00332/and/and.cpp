#include <bits/stdc++.h>
using namespace std;
long long a[200010]; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,r;
	cin>>n>>r;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort (a+1,a+n+1);
	int num=a[n];
	for (int i=n-1;i>n-r;i--){
		num=num&a[i];
	}
	cout<<num;
	return 0;
}
