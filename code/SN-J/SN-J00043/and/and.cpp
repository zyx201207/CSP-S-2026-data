#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n=0,m=0;
	cin>>n>>m;
	int a[200000]={0};
	int b[200000]={0};
	for(int i =0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int f = a[n-2];
	cout<<f;
	return 0; 
} 
