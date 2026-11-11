#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[1000000000];
string c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	string step;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<a[i];j++)
		{
			step+=c[i];
		}
	}
	int l=0,r=step.size()-1;
	int ans=0;
	while(l==r)
	{
		if(step[l]!=step[r])
		{
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}