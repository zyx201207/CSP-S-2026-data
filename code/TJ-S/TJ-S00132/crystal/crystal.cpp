#include<bits/stdc++.h>
using namespace std;
long long m,n,minn=1000000000000,flag,del;
long long a[500010],s[500010],sp[500010];
int main() 
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>m>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]; 
	}
	del=a[1]-a[0];
	s[0]=a[0];
	for(int i=1;i<n;i++)
	{
		s[i]=s[i-1]+a[i]+del;
		if(abs(s[i]-m)<minn)
		{
			minn=abs(s[i]-m);
			flag=i+1;
		}
	}
	cout<<flag<<endl;
	//Trick||Treat!
	//Oct31==Dec25?
	return 0;
}
