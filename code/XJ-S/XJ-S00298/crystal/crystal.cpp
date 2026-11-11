#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,cnt,maxn=0,m1;
	int a[500100];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(a[1]==a[n])
	{
		cout<<n<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i+1]==a[i])
		{
			continue;
		}
		cnt=1;
		m1=m;
//		cout<<"["<<a[i]<<"]"<<endl;
		while((m1>0)&&((i-cnt)>0))
		{
//			cout<<"$"<<endl;
			m1-=(a[i]-a[i-cnt]);
			if(m1<0)
			{
				break;
			}
//			cout<<a[i]<<" "<<a[i-cnt]<<" "<<"m="<<m1<<" ";
			cnt++;
		}
//		cout<<endl<<cnt<<endl;
		if(maxn<cnt)
		{
			maxn=cnt;
		}
	}
//	cout<<endl;
	cout<<maxn<<endl;
	return 0;
 } 
