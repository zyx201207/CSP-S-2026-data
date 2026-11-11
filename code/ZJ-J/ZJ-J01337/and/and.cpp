#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[300005],b[300005],ans,len,g;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	g=log2(a[i]);
    	len=max(len,g);
    }
	for(int i=len;i>=0;i--)
	{
		int k=0,c=0;
		for(int j=1;j<=n;j++)
		if((a[j]>>i)&1) k++;
		if(k<m) continue;
		for(int j=1;j<=n;j++)
		if((a[j]>>i)&1) b[++c]=a[j];
		for(int j=1;j<=c;j++) a[j]=b[j];
		n=c;
		ans+=(1<<i);
	}
	cout<<ans;
	return 0;
}