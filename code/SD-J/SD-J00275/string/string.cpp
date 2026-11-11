#include <bits/stdc++.h>
using namespace std;
const int MAXN=200000;
struct STR
{
	char x;
	int num;
}a[MAXN+10];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	unsigned long long cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].num>>a[i].x;
	}
	int la=1,ra=n,ln=1,rn=a[ra].num;

	while(la<=ra)
	{
		if(a[la].x!=a[ra].x)
		{
			cnt++;
		}
		ln++;
		rn--;
		if(ln>a[la].num)
		{
			la++;
			ln=1;
		}
		if(rn<1)
		{
			ra--;
			rn=a[ra].num;
		}
		
	}
	cout<<cnt;
	return 0;
}
