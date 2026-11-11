#include<bits/stdc++.h> 
using namespace std;
int main()
{
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	int c=0,t=0,n=0,d=0;
	cin >> c >> t >> n >> d;
	int x[n+20];
	for(int i=1;i<=n;i++)
	{
		cin >> x[i];
	}
	int o;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
		{
			if(x[i]>x[j])
			{
				if(x[i]-x[j]>d)
				{
					o++;
				}
			}
			else
			{
				if(x[j]-x[i]>d)
				{
					o++;
				}
			}
		}
	}
	cout << o << endl;
	n=0,d=0;
	cin >> n >> d;
	
	for(int i=1;i<=n;i++)
	{
		x[i]=0;
		cin >> x[i];
	}
	o=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
		{
			if(x[i]>x[j])
			{
				if(x[i]-x[j]>d)
				{
					o++;
				}
			}
			else
			{
				if(x[j]-x[i]>d)
				{
					o++;
				}
			}
		}
	}
	cout << o;
	return 0; 
}
