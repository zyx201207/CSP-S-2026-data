#include<iostream>
#include<algorithm>
using namespace std;

long long a[500005];
long long n,m;
long long ans;

long long cal;
bool flag=true;
long long d;
long long suma=0,sumb=0;
long long bkt[250];
//-100 0 100
//1 101 201
bool cmp(int aa1,int aa2)
{
	return aa1>aa2;
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
	sort(a+1,a+n+1,cmp);
	
	//check A,B
	d=a[1]-a[2];
	for(int i=1;i<n;i++)
	{
		if(a[i]-a[i+1]!=d){
			flag=false;
		}
	}


	if(flag)//µÈ²îÊýÁÐ 
	{
		for(long long i=1;i<=n;i++)
		{
			if(i*(i+1)>2*m/d)
			{
				ans=i;
				break;
			}
		}
	}
	
	else
	{
		for(long long i=1;i<n;i++)
		{
			cal=0;
			for(long long j=i+1;j<=n;j++)
			{
				cal+=a[i]-a[j];
				if(cal==m)
				{
					ans=max(ans,j-i+1);
					
				 } 
				 else if(cal>m)
				 {
				 	ans=max(ans,j-i);
				 
				 }
				 
				 if(cal>=m)break;
				
			}
		}
	}
	cout<<ans<<endl;
	return 0;
 } 
