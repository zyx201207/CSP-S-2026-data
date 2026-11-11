#include<bits/stdc++.h>
using namespace std;
int n,a[100100],q,h,qw,hw;
long long ans;
char b[100100];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
		scanf("%d%s",&a[i],&b[i]);
	hw=n-1;
	q=a[0];
	h=a[n-1];
	while(qw<hw)
	{
		 if(q==h)
		 {
			if(b[qw]!=b[hw])
				ans+=q;
			qw++;hw--;
			q=a[qw];h=a[hw];
		 }
		 else if(q>h)
		 {
			if(b[qw]!=b[hw])
				ans+=h;
			 hw--;
			 q-=h;
			 h=a[hw];
		 }
		 else if(q<h)
		 {
			if(b[qw]!=b[hw])
				ans+=q;
			 qw++;
			 h-=q;
			 q=a[qw];
		 }
	}
	printf("%lld",ans);
	return 0;
}
