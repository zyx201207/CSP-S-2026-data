#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200001];
char c[200001];
long long ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int L=1,R=n;
	while(L<R)
	{
		if(a[L]==a[R])
		{
			if(c[L]!=c[R])ans+=a[L];
			L++;R--;
		}
		if(a[L]<a[R])
		{
			if(c[L]!=c[R])ans+=a[L];
			a[R]-=a[L];
			L++;
		}
		if(a[L]>a[R])
		{
			if(c[L]!=c[R])ans+=a[R];
			a[L]-=a[R];
			R--;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
