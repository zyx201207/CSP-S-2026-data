#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010];

int totwo(int x)
{
	int s = 0;
	int cnt = -1;
	while(x>0)
	{
		cnt++;
		s = pow(10,cnt)*(x%2) + s;
		x/=2;
	}
	return s;
}

//int andd(int x,int y)
//{
//	int ans = 0;
//	int cnt = -1;
//	if(x>y)
//	{
//		while(y>0)
//		{
//			cnt++;
//			if(x%10 == y%10)
//			{
//				ans+=pow(10,cnt);
//			}
//		}
//	}
//	else	
//	{
//		while(x>0)
//		{
//			cnt++;
//			if(x%10 == y%10)
//			{
//				ans+=pow(10,cnt);
//			}
//		}	
//	}
//	return ans;	
//}

int main()
{	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	cin >> n >> m;
	for(int i = 1;i <= n;i++) 
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	if(m == 1)
	{
		cout << a[1];
	}
//	if(m==n)
//	{
//		int ans = 1;
//		for(int i = 1;i <= n;i++)
//		{
//			ans = andd(ans,totwo(i));
//		}
//		cout << ans;
//	}
	return 0;
 } 
