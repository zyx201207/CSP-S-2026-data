#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	int n,m,a[10005],ans;
	cin>>n>>m;
	for(int i=n;i<=m;i++)
	{
		cin>>a[i];
		if(a[i]==a[n]||a[i]==a[m])
		{
			if(a[n]==a[m])
			{
				int j=a[j];
				a[j]=a[i+j];
				a[i+j]=n;
			}
			a[i]++;
		}
		if(a[i]+=a[n])
		{
			a[n]+=a[m];
			a[m]++;
		}
		cout<<n;
	} 
	return 0;
}
