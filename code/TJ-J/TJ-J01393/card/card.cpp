#include<bits/stdc++.h>
using namespace std;
long long a[100005];
long long n,m,k;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cout<<a[i];
	}
	return 0;
}
