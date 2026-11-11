#include<bits/stdc++.h>
using namespace std;
long long n,cnt,sum,ans,flag1,flag2,a[200001];
char c[200001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i]>>c[i];
	for(int i=1;i<=n;i++)
	sum+=a[i];
	sum=sum/2;
	for(int i=1;i<=n;i++)
	{
		cnt+=a[i];
		if(cnt>sum) 
		{
			cnt-=a[i];
			flag1=i;
			flag2=sum-cnt;
			break;
		}
	}
	cnt=0;
	for(int i=1,j=n;i<=flag1;i++)
	{
		if(i!=flag1) cnt+=a[i];
		else cnt+=flag2;
		while(cnt-a[j]>=0)
		{
			cnt-=a[j];
			if(c[i]!=c[j]) ans+=a[j];
			j--;
		}
		a[j]-=cnt;
		if(c[i]!=c[j]) ans+=cnt;
		cnt=0;
	}
	cout<<ans;
	return 0;
}
