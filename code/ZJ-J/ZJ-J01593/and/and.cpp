//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//const int N=2*1e5+5;
//int num[N];
//bool cmp(int a,int b)
//{
//	return a>b;
//}
//signed main()
//{

//	int n,m;
//	std::cin>>n>>m;
//	for (int i=1;i<=n;i++)
//	{
//		cin>>num[i];
//	}
//	std::sort(num+1,num+n+1,cmp);
//	cout<<num[m];
//	return 0;
//}
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2*1e5+5;
int ans[N],l[N];
int log(int n)
{
	int sum=1;
	while (n>1)
	{
		n/=2;
		sum++;
	}
	return sum;
}
bool cmp(int a,int b)
{
	if (log(a)==log(b))
	{
		return a>b;
	}
	return log(a)>log(b);
}
signed main()
{
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>ans[i];
	}
	sort(ans+1,ans+n+1,cmp);
//	for (int i=1;i<=n;i++)
//	{
//		l[i]=log(ans[i]);
//	}
//	int s=1;
//	int p=0;
//	for (int i=1;i<n;i++)
//	{
//		if (l[i]==l[i+1])
//		{
//			s++;
//			if (s==m)
//			{
//				p=i+1;
//				break;
//			}
//		}
//		else
//		{
//			s=1;
//		}
//	}
//	cout<<p;
	int sum=ans[1];
	int now=0;
	for (int i=2;i<=n;i++)
	{
		sum=(sum&ans[i]);
	}
	cout<<sum;
	return 0;
}
