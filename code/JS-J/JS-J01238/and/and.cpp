#include<bits/stdc++.h>
using namespace std;
long long n,m,x=1;
int a[1000005];
string s;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		x=a[i];
	}
	sort(a,a+n);
	for(int i=n-2;i>=n-m+1;i--){
		x=x&a[i-1];
	}
	cout<<x;
	
}

