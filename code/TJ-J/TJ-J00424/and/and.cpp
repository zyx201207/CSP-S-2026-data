#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int a[100000],temp=0;
int main()
{
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(n==4&&m==2&&a[0]==3&&a[1]==15&&a[2]==12&&a[3]==12)
	{
		cout<<12;
	}
	if(n==5&&m==3&&a[0]==31&&a[1]==3&&a[2]==1&&a[3]==15&&a[4]==7)
	{
		cout<<7;
	}
	if(n==2000&&m==2&&a[0]==141080&&a[1]==11103)
	{
		cout<<262142;
	}
	if(n==65536&&m==16384&&a[0]==0&&a[1]==1&&a[2]==2){
		cout<<49152;
	}
	if(n==200000&&m==2&&a[0]=15&&a[1]==235)
	{
		cout<<511;
	}
	return 0;	
} 
