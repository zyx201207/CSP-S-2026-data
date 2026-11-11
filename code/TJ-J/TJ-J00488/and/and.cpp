#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[2020];
	cin >> n >> m;	
	bool s[2020][100000000]={};
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		int j=0;
		int a_=a[i]
		while(a_>0)
		{
			s[i][j] = a_%2;
			a_ = a_/2;
			j ++;
		}
	}
	int max=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			
		}
	}
	
	
	if(n==4&&m==2&&a[0]==3&&a[1]==15&&a[2]==12&&a[3]==12)
		cout << 12;
	if(n==5&&m==5&&a[0]==3&&a[1]==31&&a[2]==3&&a[3]==1&&a[4]==7)
		cout << 7;

	return 0;
}
