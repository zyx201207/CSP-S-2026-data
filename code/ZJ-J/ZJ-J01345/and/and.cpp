#include<bits/stdc++.h>
using namespace std;
long long a[200005],ejz[200005][32],p[500000],n,m,t,k,s,ds;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		//cout<<endl;
		t=a[i];
		k=0;
		while(t>0)
		{
			ejz[i][k]=t%2;
			t/=2;
			k++;
		}
		
	 } 
	 for(int j=31;j>=0;j--)
	 {
	 	s=0;
	 	for(int i=1;i<=n;i++)
	 	{
	 	     if(p[i]==0)
	 	     {
	 	     	if(ejz[i][j]==1) s++;
	 	     	
			  }
	 	}
	 	if(s>=m)
	 	{
	 		ds+=pow(2,j);
	 		for(int i=1;i<=n;i++) if(ejz[i][j]==0) p[i]=1;
		 }
	 }
	 cout<<ds;
	

}
