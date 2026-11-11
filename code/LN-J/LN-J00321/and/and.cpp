#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005],b;
int main()
{
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];

	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			b=max(b,i&j);
		}
	}
	cout<<b;
	return 0;
}
