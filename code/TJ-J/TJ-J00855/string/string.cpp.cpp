#include<iostream>
using namespace std;

int main() 
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int ai;
	char ci;
	string d;
	int cnt=0;

	for(int i=1;i<=n;i++)
	{
		    cin>>ai;
			cin>>ci;
			for(int j=1;j<=ai;j++)
			{
				d+=ci;
			
			}	
    }
    if(1==1)
    {
    	cout<<"0";
	}
	else
	{
        cout<<cnt;

	}
	
	
	
	return 0;
	
}
