#include<bits/stdc++.h>//>=25
using namespace std;
const int N=200010;
int n,m;
int a[200005],mx;
bool cmp(int x,int y)
{
	return x>y;
}
int main() 
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	mx=a[1];
	for(int i=2;i<=m;i++)
		mx=(mx&a[i]);
	cout<<mx;
	return 0;
 } 
//#include<bits/stdc++.h>//50
//using namespace std;
//const int N=20001;
//int n,m;
//int a[200005],dp[N][N];
//int main() 
//{
//	freopen("and4.in","r",stdin);
//	freopen("and4.out","w",stdout);
//	cin>>n>>m;
//	for(int i=1;i<=n;i++)
//		cin>>a[i];
//	for(int i=1;i<=n;i++)
//		dp[i][1]=max(dp[i-1][1],a[i]);
//	for(int i=2;i<=n;i++)
//		for(int j=2;j<=i;j++)
//			dp[i][j]=max(dp[i-1][j],(dp[i-1][j-1]&a[i]));
//	cout<<dp[n][m];
//	return 0;
//}
