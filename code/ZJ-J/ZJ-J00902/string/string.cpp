#include <bits/stdc++.h>
using namespace std;

long long cnt=0;

struct node
{
	int some;
	char zm;
}a[200007];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	int l=1;
	int r=n;
	/*char cin*/
	for(int i=1;i<=n;i++)
	{
		cin >> a[i].some >> a[i].zm;
	}
	/*left_line and right_line check*/
	while(l<r)
	{
		//cout << 1;
		/*failure*/
		if(a[l].zm != a[r].zm)
		{
			//cout << 1;
			if(a[l].some==a[r].some)
			{
				cnt+=a[l].some;
				l++;
				r--;
			}
			else if(a[l].some>a[r].some)
			{
				cnt+=a[r].some;
				a[l].some-=a[r].some;
				r--;
			}
			else
			{
				cnt+=a[l].some;
				a[r].some-=a[l].some;
				l++;
			}
		}
		/*same*/
		else
		{
			if(a[l].some==a[r].some)
			{
				l++;
				r--;
			}
			else if(a[l].some>a[r].some)
			{
				a[l].some-=a[r].some;
				r--;
			}
			else
			{
				a[r].some-=a[l].some;
				l++;
			}
		}
	}
	cout << cnt;
	return 0;
}
