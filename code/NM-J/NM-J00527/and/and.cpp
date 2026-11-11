#include<bits/stdc++.h>
using namespace std;
const int Cib=2e5+10; 
long long he[Cib],ip[Cib];
int n,m,maxx=-1; 
bool bmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>ip[i];
	}
	for(int i=1;i<=n-m+1;i++)
	{
		he[i]=ip[i];
		for(int j=i;j<=i+m-1;j++)
		{
			he[i]=(he[i]&ip[j]); 
		}
		if(maxx<he[i])
		{
			maxx=he[i];
		}
	}
	cout<<maxx<<endl;
	
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
