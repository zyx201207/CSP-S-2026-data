#include<bits/stdc++.h>
using namespace std;
void fre(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);	
}
bool cmp(int c1,int c2)
{
	return c1>c2;
}
long long a[100010];
//priority_queue<int,vector<int>,greater<int> > q;
int main()
{
fre();
long long n=0,m=0;//分别表示能量水晶的数量和最多可以进行的操作次数。
cin>>n>>m;
bool flag=1;
bool flag2=1;
int t=2;
cin>>a[1]>>a[2];
if(t-1!=a[1]||t!=a[2])
flag=0;
t++;
int t2=abs(a[1]-a[2]);
for(int i=3;i<=n;i++)
{
	//int t;
	cin>>a[i];
	if(t!=a[i]&&flag)
	flag=0;
	t++;
	if(a[i]-a[i-1]!=a[i-1]-a[i-1-1]&&flag2)
	flag2=0;
}

if(flag)
{
	int i=0;
	int ansq=1;
	while(m-i>=0)
	{
		
		m=m-i;i++;
		ansq++;
	}
	cout<<ansq-1;
	return 0;
}
if(flag2)
{
	int i=0;
	int ansq=1;
	while(m-i>=0)
	{
		
		m=m-i;i=i+t2;
		ansq++;
	}
	cout<<ansq-1;
	return 0;
}
sort(a+1,a+n+1,cmp);
int ans=1;
for(int i=1;i<n;i++)
	{
	int tans=1;
	int tmp=m,p=i;
	while(((tmp-(a[i]-a[p+1])>=0)||a[i]==a[p+1])&&p+1<=n)//防止超出范围 
	{
		p++;
		if(a[i]==a[p])
		{
			tans++;
		}else{
		
		if(tmp-(a[i]-a[p])>=0)//能量有余 
		{
			 tans++;
			 tmp=tmp-(a[i]-a[p]);
		}
		else
		{
			
			break;
		}}
		if(p+1>n)
		break;
	}
	ans=max(tans,ans);
//	cout<<ans<<"*"<<endl;
	}
cout<<ans;









return 0;
}

