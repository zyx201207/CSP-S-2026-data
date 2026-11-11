#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5005;
int c,t,n,d,x[N],ans,f[N][N],g[N][N],a[N],l;
void work();
void output();
void input()
{
	cin>>c>>t;
	while (t--)
	{
		cin>>n>>d;
		for (int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		work();
		output();
	}
}
bool judge(int l,int r)
{
	//vector<int> x1,x2;
	//cout<<"#"<<l<<" "<<r<<endl;
	int l1=l,r1=r,sum=0;
	while (l1<r1)
	{
		//cout<<1; 
		if (r1==a[r1]) return false;
		r1=a[r1];
		sum++;
	}
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	f[0][l]=1;
	for (int i=l;i<=r;i++)
		g[0][i]=1; 
	for (int i=1;i<=sum;i++)
	{
		for (int j=l+1;j<=r;j++)
		{
			f[i][j]=min(f[i][j]+g[i-1][j-1]-g[i-1][a[j]-1],3);
			g[i][j]=min(g[i][j-1]+f[i][j],3);
			//cout<<"@"<<i<<" "<<j<<" "<<f[i][j]<<" "<<g[i][j]<<endl;
		}
	}
	//cout<<"#"<<l<<" "<<r<<" "<<f[r][sum]<<endl;
	if (f[sum][r]==2)
	{
		return true;
	}
	return false;
	/*
	l1=l,r1=r;
	while (l1<r1)
	{
		//cout<<2;
		int temp=r1;
		while (temp>=l1&&x[r1]-x[temp]<=d) 
		{
			//cout<<3;
			temp--;
		}
		temp++;
		if (temp!=l1)
		{
			//cout<<3;
			if (x[temp]-x[temp-1]>d) return false;
			x2.push_back(temp);	
		}
		r1=temp;
	}
	if (x1.size()!=x2.size()) return false;
	for (int i=0;i<(int)x1.size();i++)
		if (x1[i]!=x2[i]) return true;
	return false;
	*/
}
void work()
{
	l=1;
	for (int r=1;r<=n;r++)
	{
		while (x[r]-x[l]>d) l++;
		a[r]=l;
	}
	//for (int i=1;i<=n;i++)
	//	cout<<a[i]<<" ";
	//cout<<endl;
	ans=0;
	for (int l=1;l<=n;l++)
		for (int r=l+1;r<=n;r++)
		{
			if (judge(l,r)) ans++;
		}
}
void output()
{
	cout<<ans<<endl;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	input();
	//work();
	//output();
	return 0;
}

