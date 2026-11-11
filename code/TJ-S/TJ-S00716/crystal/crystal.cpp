//#include<bits/stdc++.h>
//using namespace std;
//long long n,m,cor,ans=0;
//long long a[500001];
//bool cmp(int a,int b)
//{
//	return a<b;
//}
////int find_(long long cg,long long step)
////{
////	//ans=max(ans,cg);
////	if (step<=0)
////	{
////		cg++;
////		return cg;
////	}
////	else
////	{
////		cg++;
////	}
////	if (step==m)
////	{
////		cg+=1;
//////		step-min(a[cor]-a[cor+1],a[cor-1]-a[cor]);
//////		find_(cg,)	
////	}
//////	if(step!=m)
//////	{
//////		step-=min(a[cor]-a[cor+1],a[cor-1]-a[cor]);	
//////	}
////	cor++;
////	find_(cg,step-(a[cor-1]-a[cor]));
////}
//int main()
//{
//	//freopen("crystal.in","r",stdin);
//	//freopen("crystal.out","w",stdout);
//	cin >> n >> m;
//	for (int i=0;i<n;i++)
//	{
//		cin >> a[i];
//	}
//	sort(a,a+n,cmp);
//	if (n%2==0)
//	{
//		cor=n/2;
//	}
//	else
//	{
//		cor=(n-1)/2;
//		cout << cor << endl;
//	}
//	
//	while (a[cor+1]==a[cor])
//	{
//		cor--;
//	}
//	//cout << cor << endl;
////	while(m>0)
////	{
////		ans++;
////		m-=(a[cor]-a[cor++]);
////	}
//	cout << int(n-cor);
//	return 0;
//}

#include<bits/stdc++.h>
using namespace std;
long long n,m,cor,corn=0;
long long a[500001],w[500001],dp[500001];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	sort(a,a+n,cmp);
	if (n%2==0)
	{
		cor=n/2-1;
	}
	else
	{
		cor=(n-1)/2-1;
	}
	corn=a[cor];
	//a[cor]=0;
	//n--;
	//sort(a,a+n,cmp);
//	for (int i=0;i<n;i++)
//	{
//		w[i]=abs(a[i]-corn);
//	}
	for (int i=0;i<n;i++)
	{
		long long w=abs(a[i]-corn);
		for (int j=m;j>=w;j--)
		{
			dp[j]=max(dp[j],dp[j-w]+1);
//			for (int k=0;k<m;k++)
//			{
//				cout << dp[k] << " ";
//			}
//			cout << endl;
		}
	}
//	for (int k=0;k<n;k++)
//	{
//		cout << dp[k] << " ";
//	}
//	cout << endl;
	cout << dp[m];
	return 0;
}
