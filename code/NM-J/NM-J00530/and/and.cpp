#include<bits/stdc++.h>
using namespace std;
long long n,m,x[1000000];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	if(n==1) {cout<<x[1];return 0;}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
