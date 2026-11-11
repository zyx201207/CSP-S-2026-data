#include<bits/stdc++.h>
using namespace std;
int n,m,pos=1;
int a[200005];
int yu[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			yu[pos]=a[i]&a[j];
			pos++;
		}
	}
	sort(yu+1,yu+pos);
	cout<<yu[pos-1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}