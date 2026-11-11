#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,i;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
		}
	}
	return 0;
}
