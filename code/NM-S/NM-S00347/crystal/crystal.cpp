#include<bits/stdc++.h>
using namespace std;
long long m,n,a[500005],cha[500005],cdc[500005],ans,mmm;
bool f[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","W",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	 cin>>a[i];
	if(n==1) {cout<<1;return 0;}
	bool ff=true;
	for(int i=2;i<=n;i++)//都相等 
	 if(a[i]!=a[i-1]) {ff=false;break;}
	if(ff==true) {cout<<n;return 0;}
	sort(a,a+1+n);
	for(int i=1;i<=n;i++)
	 {
	 	cha[i]=a[i]-a[i-1];
	 	cdc[i]=cha[i]-cha[i-1];
	 }
	bool fff=true;
	for(int i=2;i<=n;i++)//等差数列 
	 if(cdc[i]!=0) {fff=false;break;}
	if(fff==true) {
		          ans=(m/cha[2])/2;
		          cout<<ans;
		          return 0;
	            }
	if(n<=5000) {
		        for(int i=n;i>=1;i--)//ai是标准
				 {
				 	mmm=m;
				 	long long t=1;
				 	while(mmm>0&&i-t>0)
					  {
					  	mmm-=a[i]-a[i-t];
						t++;
					  }
					ans=max(ans,t);
				  } 
				cout<<ans;
				return 0;
	          }
	
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
