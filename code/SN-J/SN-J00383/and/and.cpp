#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int a[N][35];
bool used[35];
int n,m,Max,ans,dd;
vector<int> ee;
int qpow(int aa,int bb)
{
	if(bb==0)return 1;
	int res=1;
	while(bb)
	{
		if(bb%2)res=res*aa;
		aa=aa*aa;
		bb/=2;
	}
	return res;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int d,cnt=0;
		cin>>d;
		while(d)
		{
			a[i][++cnt]=d%2;
			d/=2;
		}
		a[i][0]=cnt;
		Max=max(Max,cnt);
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=a[i][0];j++)cout<<a[i][j]<<' ';
//		cout<<'\n';
//	}
//	cout<<"***"<<' ';
	int num=0,dk=0;
	for(int i=Max;i>0;i--)
	{
		int sum=0;
		for(int j=1;j<=n;j++)
		{
			if(a[j][i]&&!used[j])
			{
//				num++;
				sum++;
//				used[j]=1;
			}
		}
		if(sum>=m)
		{
			num=i;
//			int dk=0;
			for(int j=1;j<=n;j++)
			{
				if(a[j][i])
				{
					dk++;
					used[j]=1;
					ee.push_back(j);
//					if(dk>m)break;
				}
			}	
//			dd++;
			ans=ans+qpow(2,i-1);	
			break;
//			if(dd==n-1)break;
		}
//		else num=now;
	}
	for(int i=num-1;i>0;i--)
	{
		int sum=0;
		for(auto j : ee)
		{
			if(a[j][i]&&used[j])sum++;
			else if(dk>m)
			{
				used[j]=0;
				dk--;
			}
		}
		if(sum>=m)ans=ans+qpow(2,i-1);
	}
	cout<<ans;
	return 0;
}
