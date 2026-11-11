#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define N 200010
void Freopen()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	return ;
}
int n,m,ans,mawei;
vector<int> A[N];
int ksm(int x,int n)
{
	int sum=1;
	while(n)
	{
		if(n&1) sum=sum*x;
		x=x*x;
		n>>=1;
	}
	return sum;
}
bool cmp(vector<int> a,vector<int> b)
{
	for(int i=0;i<=max(a.size(),b.size());i++)
	{
		if(a[i]!=b[i]) return a[i]>b[i];
	}
	return true;
}
signed main()
{
	Freopen();
	scanf("%lld%lld",&n,&m);
	for(int i=1,x;i<=n;i++) 
	{
		scanf("%lld",&x);
		while(x)
		{
			A[i].push_back(x%2);
			x/=2;
		}
		mawei=max(mawei,(int)A[i].size());
	}
	for(int i=1;i<=n;i++)
	{
		while(A[i].size()<mawei) A[i].push_back(0);
		reverse(A[i].begin(),A[i].end());
	}
	sort(A+1,A+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<A[i].size();j++)
		{
			cout<<A[i][j];
		}
		cout<<"\n";
	}
	int r=n;
	for(int i=0;i<=mawei;i++)
	{
		int cnt=0;
		for(int id=1;id<=r;id++)
		{
			if(A[id][i]==1) cnt++;
		}
		cout<<"cnt="<<cnt<<"\n";
		if(cnt<m)
		{
			r=m;
		}else
		{
			ans=ans+ksm(2,mawei-1-i);
			printf("ok!,ans=%lld\n",ans);
			int p=-1;
			for(int id=r;id>=1;id--)
			{
				if(A[id][i]==0) 
				{
					p=id-1;
					break;	
				}
			}
			if(p!=-1) r=p;
		}
	}
	printf("%lld\n",ans);
	return 0;
}

