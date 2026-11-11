#include <iostream>
#include <cstring>
using namespace std;
long long n,a[200005],cnt=0,qt=0,ht=0;
string b[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
    	cin>>a[i]>>b[i];
	}
	for (int i=1;i<=n/2;i++)
	{
		if (b[i+qt]!=b[1+n-i-ht])
		{
			cnt+=min(a[i+qt],a[1+n-i-ht]);
		}
		a[i+qt]-=min(a[i+qt],a[1+n-i-ht]);
		a[1+n-i-ht]-=min(a[i+qt],a[1+n-i-ht]);
		if(a[i+qt]>0) 
		{
			ht++;
			i--;
		}
		if(a[1+n-i-ht]>0)
		{
			qt++;
			i--;
		} 
		
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

