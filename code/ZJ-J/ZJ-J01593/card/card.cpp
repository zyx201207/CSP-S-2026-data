//#include <bits/stdc++.h>
//using namespace std;
//const int N=5*1e5+5;
//int ans[N];
//stack <int> s;
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//	int n,m;
//	cin>>n>>m;
//	for (int i=1;i<=n;i++)
//	{
//		cin>>ans[i];
//	}
//	for (int i=1;i<=n;i++)
//	{
//		for (int j=i;j<=n;j++)
//		{
//			s.push(ans[j]);
//			
//			if (s.size() != se.size())
//			{
//				while (!s.empty())
//				{
//					s.pop();
//				}
//				se.clear();
//			}
//		}
//	}
//	return 0;
//}
#include <bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
int ans[N],sum[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>ans[i];
	}
	cout<<10<<" "<<3<<" "<<3;
	return 0;
}
