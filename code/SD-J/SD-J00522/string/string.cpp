#include<bits/stdc++.h>
using namespace std;
struct stu
{
	char c;//char
	int m;//number
};
long long sz;
long long ans;
int n;
stu a[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].m>>a[i].c;
		sz+=a[i].m;
	}
	long long posl=1;
	int npl=1,npr=n;
	while(npl<=npr)
	{
		if(a[npl].m<a[npr].m)
		{
			if(a[npl].c!=a[npr].c)ans+=a[npl].m;
			npl++;
			posl+=a[npl].m;
			a[npr].m-=a[npl].m;
		}
		else if(a[npl].m==a[npr].m)
		{
			if(a[npl].c!=a[npr].c)ans+=a[npl].m;
			npl++;
			npr--;
		}
		else if(a[npl].m>a[npr].m)
		{
			if(a[npl].c!=a[npr].c)ans+=a[npr].m;
			npr--;
			posl+=a[npr].m;
			a[npl].m-=a[npr].m;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
