#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("string,in","r",stdin);
freopen("string,out","w",stdout);
string c[200005],d=0;
int n,a[200005],sum[200005]={0};
cin>>n;
for(int i=0;i<=n;i++)
{
	cin>>a[i];
	cin>>c[i];
}
for(int i=0;i<=n;i++)
{
	for(int j=0;j<=i;j++)
	{
		d+=c[i];
	}
 } 
int num=0;
if(n%2==0){
	for(int i=0;i<=n;i++)
	{
		if(sum[i]==0)
		{
			num++;
		}
	}
}
cout<<num<<endl;
	return 0;
}
