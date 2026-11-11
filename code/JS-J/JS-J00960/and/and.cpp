#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int j=0;j<n;j++)
		for(int i=j+1;i<=n;i++)
			if(a[i-1]<a[i])
				swap(a[i-1],a[i]);

	cout<<a[1];
	return 0;
}
