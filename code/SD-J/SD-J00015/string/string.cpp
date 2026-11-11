#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int N = 2e5+7;
int n;
long long ans,s1,s2,a[N];
char b[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	int l = 1,r = n;
	while(l<r)
	{
		if(a[l]>=a[r])
		{
			if(b[l]!=b[r])ans+=a[r];
			a[l]-=a[r],r--;
		}
		else if(a[l]<a[r])
		{
			if(b[l]!=b[r])ans+=a[l];
			a[r]-=a[l],l++;
		}
	}
	cout<<ans;

	fclose(stdin);
	fclose(stdout);
	return 0;
 }

