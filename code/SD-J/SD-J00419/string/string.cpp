#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100004];
char c[100004];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0,ans=0;
	scanf("%lld",&n);
	string s;
	for(int i=1;i<=n;++i)
	{
		scanf("%lld %c",&a[i],&c[i]);
		for(int j=1;j<=a[i];++j)s+=c[i];
		sum+=a[i];
	}
	for(int i=0,j=sum-1;i<=sum/2-1;++i,--j)
	{
		if(s[i]!=s[j])++ans/*,printf("%lld %c %c\n",i,s[i],s[j])*/;
	}
//	cout<<s<<endl;
	printf("%lld",ans);
	return 0;
}

