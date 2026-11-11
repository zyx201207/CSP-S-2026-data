#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
long long int a[1000],b[1000],i,k,m,j,l,s,d,h,t,f,x,y;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.cout","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
	cout<<"1";
	s=1;	
    }
	else
	cout<<"0";
	for(i=1;i<=s1.size()-1;i++)
	a[++k]=s1[i]-'0';
	for(i=1;i<=s2.size()-1;i++)
	b[++j]=s2[i]-'0';
	t=a[0]+a[1];
	m=b[0]+b[1];
	if(t==m&&s==1)
	{
		cout<<"1";
		l=1;
	}
	else
	cout<<"0";
	f=('C'-'0');
	x=('D'-'0');
	if(t==m&&s==1&&a[2]<=f&&b[2]<=f||a[2]>=x&&b[2]>=x&&t==m&&s==1)
	{
		cout<<"1";
		y=1;
	}
	else
	cout<<"0";
	d=('C'-'0')+('D'-'0');
	h=a[2]+b[2];
	if((a[2]+1)==b[2]&&s==1&&l==1&&h!=d&&y==1||a[2]==(b[2]+1)&&s==1&&l==1&&h!=d&&y==1)
	{
		cout<<"1";
	}
	else
	cout<<"0";
	fclose(stdin);
	fclose(stdout);
	return 0;
}