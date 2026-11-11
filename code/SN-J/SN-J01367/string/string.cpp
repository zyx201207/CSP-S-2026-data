#include<iostream>
#include<cstdio>
using namespace std;
long long int x[100000];
char y[100000];
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int p;
	int q=0;
	int a;
	cin>>a;	
	for(int temp=0;temp<a;temp++)
	{
	    cin>>x[temp]>>y[temp];
	}
	for(int z=0;z<a-1;z++)
	{
		if(y[z]!=y[z+1])
		{
			q+=1;
		}
	}
		
    if(q==0)
    {
    	cout<<q;
	}
	for(int z=0;z<a-1;z++)
	{
		if(x[z]!=x[z+1])
		{
			p+=1;
		}
	}
	if(p==0)
	{
		if(a%2==0)
		{
			cout<<a*x[2]/2;
		}
		else
		{
			cout<<(a-1)*x[2]/2;
		}
	}
	return 0;
}
