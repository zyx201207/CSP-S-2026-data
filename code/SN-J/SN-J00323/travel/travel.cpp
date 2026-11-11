#include<iostream>
#include<set>
#include<string>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2;
	int a='F';
	int b='E';
	int c='C';
	int d='B';
	int e='A';
	int f='D';
	int g=01;
	int h=05;
	int n=02;
	int m=03;
	int o=04;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
		
	}
	else
	{
		cout<<0;
	}
	int i=g;i<=h;
	int j=g;j<=h;
			if(i==j)
			{
				cout<<1;
			}
			else
			{
				cout<<0;
		}
		int k=g;k<=h;
		int l=g;l<=h;
		
		    		if(k==g,l==n||k==g,l==m||k==n,l==g||k==n,l==m||k==m,l==g||k==m,l==n||k==o,l==h||k==h,l==o)
		    		{
				    cout<<1;
			        }
			    else
			    {
			    	cout<<0;
            }
		    				if(c2-s2==1||s2-c2==1)
		    				{
		    					cout<<1;
							}
							else
							{
								cout<<0;
							}
						
		return 0;
}
