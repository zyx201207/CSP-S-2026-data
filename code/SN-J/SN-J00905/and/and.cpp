#include<bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("and.in","r",stfin);
	//freopon("and.out","w",stdout);
	int n,m;
	cin>> n>>m;
	int a[n];
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		m = a[i] | a[i+1];
	}
	cout<< m;
	return 0;
}
