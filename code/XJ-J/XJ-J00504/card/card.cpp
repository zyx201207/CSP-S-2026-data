#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],c[500005],t,b[500005],cnt[50005],j,pp;
int main ()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++)cin>>a[i];
	 t=n;
	 pp=1;
	 while (t--)
	 {
	 	memset(b,0,sizeof(b));
	 	memset(cnt,0,sizeof(cnt));
	 	for (int i=pp;i<=n;i++)
	 	{
	 		cnt[a[i]]++;
			 if(cnt[a[i]]!=1) 
			 {
			 memset(b,0,sizeof(b));
			 j=0;
			 b[++j]=a[i]; 
			 } 
			 else b[++j]=a[i];
		 }
		 for (int i=1;i<=j;i++)
		 {
		 c[b[i]]++;
		 }
		 pp++;
	 }
	 for (int i=1;i<=m;i++)cout<<c[i]<<' ';
	 return 0;
}
