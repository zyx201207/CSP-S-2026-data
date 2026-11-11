#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int a[N],t[M];
int n,m;
int w[N],num[N];
vector<int>v;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=500)
	{
		for(int i=1;i<=n;i++)//game
		{
			v.clear();
			for(int j=i;j<=n;j++)//card
			{
				int s=v.size();
				for(int k=0;k<s;k++)
					if(v[k]==a[j])
					{
						for(int l=s-k;l>0;l--)
							v.pop_back();
						break;
					}
				v.push_back(a[j]);
			}
			for(int k:v)
				t[k]++;
		}
	}
	else if(m==2)
	{
		t[a[n]]=n;
		int x=a[n],l=n-1,r=n-1;
		bool b=0;
		while(!b||a[l]==x)
		{
			if(a[l]!=x)
				b=1,r=l;
			l--;
		}
		t[1]=r-l+1;
	}
	else 
	{
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			t[a[i]]++;
			if(a[i]!=a[i+1])
				t[a[i+1]]=t[a[i]];
		}	
	}
	for(int i=1;i<=m;i++)	
		cout<<t[i]<<" ";
	return 0;
}
