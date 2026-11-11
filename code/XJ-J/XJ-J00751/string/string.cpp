#include<bits/stdc++.h>
using namespace std;
string tmp="";
int cnt;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,x;
	char num;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>num;
		for(int j=1;j<=x;j++)
		{
			tmp+=num;
		}
	}
	int len=tmp.size();
	int l=0,r=len-1;
	while(l<=r)
	{
		if(tmp[l]!=tmp[r])
		{
			tmp[l]=tmp[r];
			cnt++;
		}
		l++,r--;
	}
	cout<<cnt;
	return 0;
}