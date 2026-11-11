#include <bits/stdc++.h>
using namespace std;
int n,a[200050];
char s[200050];
long long L=0,x=0,ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
		L+=a[i];
	}
	int i=0,li=1,ri=n;
	long long l=0,r=L;
	while(x<L/2)
	{
		i++;
		x+=a[i];
	}
	while(li<=i && ri>=i){
		if(a[li]>a[ri])
		{
			if(s[li]!=s[ri]) ans+=a[ri];
			a[li]-=a[ri];
			ri--;
		}
		else if(a[li]==a[ri])
		{
			if(s[li]!=s[ri]) ans+=a[ri];
			li++;
			ri--;
		}
		else{
			if(s[li]!=s[ri]) ans+=a[li];
			a[ri]-=a[li];
			li++;
		}
	}
	printf("%lld",ans);
	return 0;
}
