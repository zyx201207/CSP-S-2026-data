#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,j=1,s=0;
	int a[1000000],b[1000000];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=m;i--){
		b[j]=a[i];
	}
	for(int i=1;i<n;i+=2){
		s=s+b[i]|b[i+1];
	}
	cout<<s;
	return 0;
}
