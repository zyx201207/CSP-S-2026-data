#include<bits/stdc++.h>
using namespace std;
char st[200000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n,stlen=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a;
		char c;
		cin>>a>>c;
		for(int j=0;j<a;j++)
		{
			st[stlen]=c;
			stlen+=1;
		}
	}
	int l=0,r=stlen-1,num=0;
	while(l<r)
	{
		if(st[l]!=st[r])
		{
			num+=1;
		}
		l+=1;
		r-=1;
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
