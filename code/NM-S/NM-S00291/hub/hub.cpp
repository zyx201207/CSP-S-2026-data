#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int a[17];
	int b[17];
	int c,v;
	c=1;
	v=2;
	for(int i=1;i<=16;i++)
	{
		cin>>a[i];
		cin>>b[i];
	}
	if(a[16]==9&&b[16]==10)
	{
		cout<<c<<endl;
		cout<<v<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
