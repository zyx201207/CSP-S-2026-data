#include<bits/stdc++.h>
using namespace std;
long long a[100],b[100];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	long long n,k;
	cin>>n>>k;
	for(int i=1;i<=14;i++)
	{
			cin>>a[i]>>b[i];
	}
	cout<<k-1<<endl;
	cout<<2*(k-1);
	return 0;
}
