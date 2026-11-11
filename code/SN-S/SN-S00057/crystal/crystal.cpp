#include<bits/stdc++.h>
using namespace std;
long long a[100];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,k1=0,k2=0,finn=0;
	double sum=0;
	cin>>n>>m;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int y = a[(n-1)/2];
	for (int i=0;i<n;i++){
		if (a[i] == y){
			finn++;
		}
	}
	cout<<finn+(n-1)/2;
	return 0;
}
