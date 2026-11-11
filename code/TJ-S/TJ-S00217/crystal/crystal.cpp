#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	long long n,m,cnt=0,maxn=0;
	
	cin>>n>>m;
	long long a[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort (a+1,a+n+1);
	long long b[n+5]={};
	long long mid=a[n/2];
	for(int i=1;i<=n;i++)
	{
		b[i]=abs(mid-a[i]);
	}
	sort (b+1,b+n+1);
	
	for(int i=1;i<=n;i++)
	{
		if(b[i]<=m)
		{
			m-=b[i];
			cnt++;
		}
		else break;
	}
	cout <<cnt;
	return 0;
}

