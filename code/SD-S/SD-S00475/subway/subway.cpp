#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,d;
int a[100005];
int a1n[N],a2n[N];
int  A1n[N],A2n[N];
int  A1[N],A2[N];
void sol()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	  a1n[i]=a2n[i]=0;
	    
	int a2=1;
	for(int i=1;i<=n;i++)
	{
		while(a2<n && a[a2+1]-a[i]<=d) a2++;
		A2[i]=a2;
	}
	int a1=n;
	for(int i=n;i>=1;i--)
	{
		while(a1>1 && a[i]-a[a1-1]<=d) a1--;
		A1[i]=a1;
	}
	
	for(int i=1;i<=n;i++)
	{
	 if(A2[i]-i ) a1n[A2[i]]+=a1n[i]+1;
	 if(i-A1[i])	a2n[A1[i]]++;
	}
	int ans=0;
	for(int i=1;i<n;i++)
	{
		 ans+=a1n[i+1]*a2n[i];
		//cout<<a1n[i+1]<<" "<<a2n[i]<<endl;
		ans+=a1n[i+1]*a2n[i];
	 } 
	 for(int i=1;i<=n;i++)
	 cout<<ans<<endl;
	  cout<<endl;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
     
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	  cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=n;j++)
		{
			 int x,y;
			 cin>>x>>y; 
		} 
	}
	return 0;  	
} 
