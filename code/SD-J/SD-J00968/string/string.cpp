#include<iostream>
using namespace std;
struct qp
{
	long long a;
	char b;
}c[200000];
long long m,l,r,n;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d %c",&c[i].a,&c[i].b);
	l=0,r=n-1;
	while(n>1)
	{
		if(c[l].b!=c[r].b)
		{
			c[l].a-=min(c[l].a,c[r].a),c[r].a-=min(c[l].a,c[r].a),m+=min(c[l].a,c[r].a);
			if(c[l].a==0)l++,n--;
			if(c[r].a==0)r--,n--;
		}
		if(c[l].b==c[r].b&&c[l].a!=c[r].a)
		{
			c[l].a-=min(c[l].a,c[r].a),c[r].a-=min(c[l].a,c[r].a);
			if(c[l].a==0)l++,n--;
			if(c[r].a==0)r--,n--;
		}
	}
	printf("%d",m);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

