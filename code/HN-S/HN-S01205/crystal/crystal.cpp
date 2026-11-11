#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){return x<y;}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[500010],cnt=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];	
	}
	sort(a+1,a+n+1,cmp);
	for(int i=0;i<n;i++)
	{
		if(a[i]-a[0]<m) cnt++;
	}
	cout<<cnt<<endl;
	return 0;
} 
