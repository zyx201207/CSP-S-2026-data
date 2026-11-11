#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	int mx=-1;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	cout<<n<<" "<<m<<a[1];
	fclose(stdin);
	fclose(stdout);
	return 0;

} 
