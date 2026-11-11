#include<bits/stdc++.h>
using namespace std;
int a[200010];
int b[200010];
int aa[200010];
int bb[200010];
int main()
{
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,cnt = 1;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	char f,l=1;
	for(int i = 1;i <= m;i++)
	{
		b[i]=a[n-i+1];
		aa[i]=b[i]%2;
		b[i]/=2;
	    
	
		f=aa[i];
		bb[i]=(l&f)-'0';
		l=f;
	
		for(int j = 1;j <= i;j++)
		{
		
		bb[i]*=2;
		}
		cnt += bb[i];
	}
	cout << cnt;
	return 0;
}
