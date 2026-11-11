#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500050],t,cnt,cntmax,t2;
bool y=1;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=n-1;i>0;i--)
	{
		cnt=1;
		t2=m;
		t=a[i];
		y=1;
		for(int j=i-1;j>=0&&y==1;j--)
		{
			if(t-a[j]>t2)
			{
				y=0;
			}
			else
			{
				t2-=t-a[j];
				cnt++;
			}
			//cout<<a[i]<<" "<<a[j]<<" "<<cnt<<'\n';
		}
		if(cnt>cntmax)
		{
			//cout<<a[i]<<'\n';
			cntmax=cnt;
		}
	}
	cout<<cntmax<<'\n';
	/*for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}*/
	return 0;
}
