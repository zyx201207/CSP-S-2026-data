#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],v=-1,da=-1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	  cin>>a[i];
	if(n==1) {cout<<a[1];return 0;}
	if(m==n) {v=a[1]&a[2];
			  for(int i=3;i<=n;i++)
			    v=v&a[i];
			  cout<<v;return 0;
	         }
	if(m==1) {for(int i=1;i<=n;i++) v=max(v,a[i]);cout<<v;return 0;}
	if(m==2) {for(int i=1;i<n;i++)
		       for(int j=i+1;j<=n;j++)
		         v=max(v,a[i]&a[j]);
				 cout<<v;return 0;
			 }
	if(m==3) {
			  for(int i=1;i<n-1;i++)
			    for(int j=i+1;j<n;j++)
			      for(int o=j+1;o<=n;o++)
			        v=max(v,a[i]&a[j]&a[o]);
			        cout<<v;return 0;
	         }
	if(m-1==n) {int p=1;
				for(int j=1;j<=n;j++)
				{v=a[1]&a[2];
				  for(int i=3;i<=n;i++)
				  {
				  	if(i==p) continue;
				  	v=v&a[i];
				  }
				  p++;
				  da=max(da,v);
				}
				cout<<da;return 0;
	           }
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
