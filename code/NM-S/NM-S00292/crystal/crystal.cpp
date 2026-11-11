#include<bits/stdc++.h> 
using namespace std;
long long n,m,maxx=-2e9,qshh=0;
const int N=5e5+100;
long long a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(m>=(a[i+1]-a[i])*i) {
			                    m=m-(a[i+1]-a[i])*i;
			                    a[i]+=a[i+1]-a[i];
			                    for(int j=1;j<i;j++)
			                    {
			                    	a[j]=a[i];
								}
			                    qshh++;
		                       }
	}
	cout<<qshh;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
