//杨云铄 西安市第二十六中学 SN-00710 
#include<iostream>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long n,m,a[100005],MAX_and=-10000000;
	cin>>n>>m;
	for(long i=1;i<=n;i++) cin>>a[i];
	for(long i=1;i<=n;i++){
		for(long j=i+1;j<=n;j++)
		{
			if(a[i]&a[j]>=MAX_and) MAX_and=a[i]&a[j];
		}
	}
	cout<<MAX_and;
	
 } 
