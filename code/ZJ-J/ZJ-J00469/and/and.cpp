 

#include<bits/stdc++.h>
using namespace std;
bool a[200001][30];
int cnt[30];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,mmax=-1,all;
	cin>>n>>m;
	for(int ii=1;ii<=n;ii++)
	{
		int x,i=0;
		cin>>x;
		if(ii==1)
		{
			all=x;
		}else{
			all&=x;
		}
		mmax=max(mmax,x);
		int xx=x;
		while(xx)
		{
			a[ii][i]=xx%2;
			if(xx%2)
			{
				cnt[i]++;
			}
			xx/=2;
			i++;
		}
	}
	if(m==1)
	{
		cout<<mmax;
		return 0;
	}else if(m==n)
	{
		cout<<all;
		return 0;
	}
	/*
	for(int ii=1;ii<=n;ii++)
	{
		for(int i=29;i>=0;i--)
		{
			cout<<a[ii][i];
		}cout<<'\n';
	}*/
	int big=0;
	vector<int>aa,bb;
	long long ans=0;
	for(int i=29;i>=0;i--)
	{
		if(big==0)
		{
			if(cnt[i]<m)
			{
				continue;
			}else{
				big=i;
			}
		}
		//cout<<big<<"\n\n";
		if(big)
		{
			int ccnt=0;
			for(int j=1;j<=n;j++){
			if(a[j][big]==1&&a[j][i]==1)
			{
			ccnt++;
			}
			}
			//cout<<i<<' '<<ccnt<<'\n';
			ans=ans*2+(ccnt>=m?1:0);
		}
	}
	cout<<ans;
	return 0;
}
