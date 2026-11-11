#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n,c=0;
    cin>>n;
    char a[n];
    int b[n];
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
        cin>>a[i];
        c+=b[i];
	}
	char x[c];
	cout<<c;
	int e=0;
	for(int i=0;i<n;i++) 
	{ 
		for(int j=1;j<=b[i];j++)
		{
			e++;
		    x[e]=a[i];
		}
		e+=b[i];
	}
	int u=0;
   	int y=1,s=c-1;
    while(s>y)
    {
       	if(x[y]!=x[s])
       	{
       	    u++;
			cout<<x[s]<<" ";
		}
		y++;
		s--;
	}
	cout<<u;
	return 0;
}
