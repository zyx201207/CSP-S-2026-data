#include<bits/stdc++.h>
using namespace std;
long long n,m,sum;
int a[100005],he[100005],b[100005];
int main()
{
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
    		b[i]=a[i+1]-a[i];
    		he[i]=he[i-1]+i*b[i];
    		if(he[i]<=m)
    		{
    			sum++;
			}
			else if(he[i]==m)
			{
				sum++;
				break;
			}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
