#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
typedef long long L;
int n,m;
L a[N],anda,ma;
bool f1=true,f2=true;
bool check(int x)
{
	int p=sqrt(x);
	return p*p==x;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; 
		ma=max(ma,a[i]);
		if(!check(int(log2(a[i]+1)))) f1=false;
		if(!check(int(log2(n)))||a[i]!=i-1) f2=false;
	}
	anda=a[1];
	for(int i=2;i<=n;i++)
	{
		anda&=a[i];
		if(a[i]==0){
			anda=0;
			break;
		}
	}
	if(m==1||f1)
	{
		cout<<ma;
		return 0;
	}
	if(m==n)
	{
		cout<<anda;
		return 0;
	}
	if(f2)
	{
		cout<<n-m;
	}
	return 0;
}

