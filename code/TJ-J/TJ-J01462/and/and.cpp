#include<iostream>
using namespace std;
int a[100000],k[100000],l;
int main() {
	int n,m;
	cin>>n,m;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	for(int i=0;i<n;i++){
		k[i]=a[i] and a[i+1];
		l=k[i]+k[i+1];
	}
	cout<<l;
	return 0;
}
