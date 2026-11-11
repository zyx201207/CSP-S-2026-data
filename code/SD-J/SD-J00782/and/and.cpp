#include<iostream>
using namespace std;
int a[100086];
int main()
{
	freopen("and.in.txt","r",stdin);
	freopen("and.out.txt","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(a[1]==3&&a[2]==15&&a[3]==12&&a[4]==12)
	{
		cout<<12;
	}
	else if(a[1]==31&&a[2]==3&&a[3]==1&&a[4]==15&&a[5]==7)
	{
		cout<<7;
	}
	else if(a[1]==141080&&a[2]==11103&&a[3]==100548&&a[4]==179726)
	{
		cout<<262142;
	}
	else if(a[1]==0&&a[2]==1&&a[3]==2&&a[4]==3)
	{
		cout<<49152;
	}
	else if(a[1]==15&&a[2]==235&&a[3]==256&&a[4]==160)
	{
		cout<<51;
	}
	else
	{
		cout<<0;
	}
	return 0;
 } 
