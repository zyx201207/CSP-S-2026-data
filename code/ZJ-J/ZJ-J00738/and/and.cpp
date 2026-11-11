#include<bits/stdc++.h> 
using namespace std;
const int N=2e5+5;
long long a[N],n,m;
long long Max=0;
void dfs(const int &step,const int &Choose,const long long &sum)
{
	//cout<<step<<" "<<Choose<<" "<<sum<<"\n";
	if(Choose==m)
	{
		Max=max(Max,sum);
		return ;
	}
	if(step>n) return ;
	//if(Choose>m) return ;
	if(Choose==0) dfs(step+1,Choose+1,a[step]);
	else dfs(step+1,Choose+1,sum&a[step]);
	dfs(step+1,Choose,sum);
}
bool cmp(long long x,long long y)
{
	return x>y;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=20)
	{
		dfs(1,0,0);
		cout<<Max<<"\n";
	}
	else if(m==1)
	{
		for(int i=1;i<=n;i++) Max=max(Max,a[i]);
		cout<<Max<<"\n";
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j)Max=max(Max,a[i]&a[j]);
			}
		}
		cout<<Max<<"\n";
	}
	else 
	{
		bool same=true;
		for(int i=1;i<=n;i++)
		{
			int x=a[i]+1;
		//	cout<<log2(x)<<"\n";
			if(log2(x)!=ceil(log2(x))) 
			{
		//		cout<<"Sp: "<<log2(x)<<"\n";
				same=false; 
			}
		}
		if(same)
		{
			vector<long long>b;
			for(int i=1;i<=n;i++)
				b.push_back((int)(log2(a[i]+1)));
			sort(b.begin(),b.end(),cmp);
			int i=0;
			while(m--) 
			{
				//cout<<b[i]<<"\n";
				if(m==0)
				{
					cout<<pow(2,b[i])-1<<"\n";
					break;
				}
				i++;
			}
		}
	}
	return 0;
}
