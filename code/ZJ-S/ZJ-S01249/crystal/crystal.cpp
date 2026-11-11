#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,maxx=1;
long long m,a[N],b[N];
bool flagA=true,flagB=true;
long long get_sub(int y,int num)
{
	long long temp=0;
	for(int i=y-1;i>=y-num+1;i--)
	{
		temp+=b[i]*(num-y+i);
	}
	return temp;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(a[n]!=n) flagA=false;
	for(int i=n-1;i>=1;i--)
	{
		b[i]=a[i+1]-a[i];
		if(a[i]!=i) flagA=false;
		if(i!=n-1&&b[i]!=b[i+1]) flagB=false;
	}
	if(flagA)
	{
		maxx=floor((double)((1.0+(double)sqrt(1.0+8.0*m))/2.0));
		if(maxx>n) maxx=n;
		cout<<maxx<<endl;
	}
	else if(flagB)
	{
		int t=b[1];
		maxx=floor((double)((t+(double)sqrt(t*t+8.0*m*t))/(2.0*t)));
		if(maxx>n) maxx=n;
		cout<<maxx<<endl;
	}
	else
	{
		for(int i=n;i>=maxx;i--)
		{
			while(get_sub(i,maxx+1)<=m)
				maxx+=1;
		}
		cout<<maxx<<endl;
	}
	return 0;
}