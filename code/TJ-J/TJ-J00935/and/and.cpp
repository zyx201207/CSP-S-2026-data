#include <iostream>
#include <string>

using namespace std;
int a[10000];
int b;
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int j=2;j<=n;j++)
	{
		if(a[j]>a[j-1])
		{
			b=a[j-1];
			a[j-1]=a[j];
			a[j]=b;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<=n;j++)
		{
			if(a[j]>a[j-1])
			{
				b=a[j-1];
				a[j-1]=a[j];
				a[j]=b;
			}
		}
	}
	int ans=a[1];
	for(int i=2;i<=m;i++)
	{
		ans=ans and a[i];
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
