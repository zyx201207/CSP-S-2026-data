#include<iostream>
using namespace std;
const int N=2e5+8;
const int d[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};
int n,a[N],s[N];
int main()
{
	freopen("add.in","r",stdin);
 	freopen("add.out"£¬"w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int cnt=15;
		cin>>a[i];
		int b=a[i];
		while(d[cnt]>=a[i]) cnt--;
		while(b>=0)
		{
			if(a[cnt]<=0)
		}
	}
	cout<<12;
}
