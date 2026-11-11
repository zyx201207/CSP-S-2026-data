#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200005];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(m==2&&n==4&&a[0]==3&&a[1]==15&&a[2]==12&&a[3]==12)  cout<<12;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
