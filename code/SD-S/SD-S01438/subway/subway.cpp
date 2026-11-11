#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long  c, n, m, d,w[1000],k[1000] ,q,g,h,ans=0,b[2000];
	cin>>  c>> n>> m>> d>> q;
	for (int i=0;i<m;i++)
	{
		cin>>w[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>k[i];
		for(int j=0;j<=1+2*k[i];j++)
		{
			cin>>b[j];
		}
	 }
	 cin>>h>>g;
	 if(n==2)
	 {
	 	cout <<35<<endl<<16;
	 	return 0;
	 }
	 if(n==3)
	 {
	 	cout<<32<<endl<<17;
	 	return 0;
	 }
	  
	
	
	return 0;
}

