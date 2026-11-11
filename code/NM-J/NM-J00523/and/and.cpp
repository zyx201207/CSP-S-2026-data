#include<bits/stdc++.h>
using namespace std;
int zhi[100010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int t,a,da=-7891;
	cin>>t>>a;
	for(int i=1;i<=t;i++)
	{
		cin>>zhi[i];
		
	}
	sort(zhi+1,zhi+1+t);
	for(int i=1;i<=t;i++)
	{
		if(zhi[i]&zhi[i-1]>da) da=zhi[i]&zhi[i-1];
    }
	cout<<da;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
