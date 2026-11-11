#include<bits/stdc++.h>
using namespace std;
char d[200005];
int v[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	cin>>d[i];
        cin>>v[i];
    }
    int u=0;
    int p=0;
    n-=1;
    while(u!=n)
    {
    	if(d[u]==d[n])
    	{
    		if(v[u]>v[n])
    		{
    			v[u]-=v[n];
    			n--;
			}
			else if(v[u]<v[n])
			{
				v[n]-=v[u];
				u++;
			}
			else
			{
				u++;
				n--;
			}
		}
		else
		{
			if(v[u]>v[n])
    		{
    			p+=v[u]-v[n];
    			v[u]-=v[n];
    			n--;
			}
			else if(v[u]<v[n])
			{
				p+=v[n]-v[u];
				v[n]-=v[u];
				u++;
			}
		}
	}
	cout<<p;
	fclose(stdin);
	fclose(stdout);
    return 0;
}
