#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,num,q,Xlong,ans;
	string x,X;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>num>>x;
		for(int j=0;j<num;j++)
		{
			X+=x;
			Xlong++;
		}
	}
	for(int i=1;i<n;i++)
	{
		if(n[i]==n[i-1])q++;
	}
	if(q==n-1)
    {
        cout<<0;
        return 0;
    }
	for(int i=0;i<Xlong/2;i++)
    {
        if(X[i]!=X[Xlong-i-1])ans++;
    }
    cout<<ans;
	return 0;
}
