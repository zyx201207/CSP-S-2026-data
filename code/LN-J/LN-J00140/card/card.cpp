#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(a[n]==a[n-1]&&a[n]==1)
	{
		cout<<n<<' '<<0;
	}
	else if(a[n]==a[n-1]&&a[n]==2)
	{
		cout<<0<<' '<<n;
	}
	else
	{
		cout<<n<<' '<<n;
	}
	return 0;
}
