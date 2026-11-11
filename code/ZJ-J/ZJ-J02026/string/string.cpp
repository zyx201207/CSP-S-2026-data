#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n,a,num=0,d[200000][2],head=0,tail;
	char b;
	cin>>n;
	tail=n-1;
	for(int i=0;i<n;i++)
	{
	cin>>a>>b;
	d[i][0]=a;
	d[i][1]=int(b);
	}
	while(head<tail) 
		{
		if(d[head][1]!=d[tail][1])
			{
			if(d[head][0]=d[tail][0])
				{
					num+=d[tail][0];
					head++;
					tail--;
				}	
			if(d[head][0]<d[tail][0])
				{
				num+=d[head][0];
				d[tail][0]-=d[head][0];
				head++;
				}
			else
				if(d[head][0]>d[tail][0])
				{	
				num+=d[tail][0];
				d[head][0]-=d[tail][0];
				tail--;
				}
			}
		else
			{
			if(d[head][0]=d[tail][0])
				{
					head++;
					tail--;
				}
			if(d[head][0]<d[tail][0])
				{
				d[tail][0]-=d[head][0];
				head++;
				}
			else
				if(d[head][0]>d[tail][0])
				{	
				d[head][0]-=d[tail][0];
				tail--;
				}
			}
		}
	cout<<num;
	return 0;
}
