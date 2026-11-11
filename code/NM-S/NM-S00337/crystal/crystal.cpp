#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500010],chahe,da,jia;//chahe是差的和,累加器 .jia是算个数的累加器 
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==0){cout<<0;return 0;}
	else
	{
		sort(a+1,a+1+n);
		da=a[n];
		for(int i=1;i<=n;i++)
		{
			chahe+=da-a[i];
			jia++;
			if(chahe>m) {da=a[n-1];n--;i=1;jia=0;chahe=0;}
		}
	}
	cout<<jia+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
