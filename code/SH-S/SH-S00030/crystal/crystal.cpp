#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[5000005],b[500005];
int main()
 {
 	freopen("crystal.in","r",stdin);
 	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long cnt;
	long long maxn=0;
 	long long maxa=0;
	bool flag=true;
 	for(int i=1;i<=n;i++)
 	{
 		cin>>b[i];
 		maxa=max(maxa,b[i]);		
 		a[b[i]]++;
 		maxn=max(a[b[i]],maxn);
 		if(a[b[i]]==maxn)
 		{
 			cnt=b[i];
		}
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)
	{
		if(i>2&&b[i]-b[i-1]!=b[i-1]-b[i-2])
 		{
 			flag=false;
		}
	}
	long long answer=1;
	if(flag)
	{
		int ch=b[2]-b[1];
		int t=1;
		while(m>=t*ch)
		{
			m-=t*ch;
			t++;
			answer++;
		}
		if(answer>n)
		{
			answer=n;
		}
		cout<<answer;
		return 0;
	}
	if(maxn==1)
	{
		if(n%2==0)
		{
			cnt=b[n/2]; 
		}
		else
		{
			cnt=b[n/2+1];
		}
	}
	int j;
	for(int i=1;i<=n;i++)
	{
		if(b[i]==cnt)
		{
			j=i-1;
			break;
		}
	}
	long long ans=maxn;
	while(m>=cnt-b[j]&&j>=1)
	{
		m-=cnt-b[j];
		ans++;
		j--;
	}
	cout<<ans;
	return 0;
 }
