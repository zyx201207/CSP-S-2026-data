#include<bits/stdc++.h>
using namespace std;
int n,a[200200],sum;
char c[200200];
long long qzh[200200],ans;
string s=" ";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
		sum+=a[i];
	}
	int sm1=((sum+1)/2);
	int sm2=sum+1-sm1;
	while(sm1!=0)
	{
		if(s[sm1]!=s[sm2])ans++;
		sm1--,sm2++;
	}
	cout<<ans;
	return 0;
}
