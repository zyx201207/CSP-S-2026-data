#include <bits/stdc++.h>
using namespace std;
struct st{
	char c;
	int nu;
};
long long n,ans,len,sum,x,t;
char a[200005],d;
int huiwen()
{
	for(int i=1;i<=t/2;i++)
	{
		if(a[i]!=a[t-i])ans++;
	}
	return ans;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> x >> d;
		for(int j=1;j<=x;j++)
		{
			t++;
			a[t]=d;
		}
	} 
	cout << huiwen();
	return 0;
}
