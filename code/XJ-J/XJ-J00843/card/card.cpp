#include <bits/stdc++.h>
using namespace std;
int n,m,a[3000000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cout<<n-i+1;
	}
	return 0;
}