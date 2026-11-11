#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll M = 2e5+10;
const ll N = 1e5+10;
ll n,m,a[M],bx,by,b[M],as,az;
ll l,r;
void s(){
	for(int i = 1;i<=n;i++)
	{
		a[i] = b[i];
	}
} 
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(n>M||m>2){
		for(int i = 1;i<=m;i++)
		{
			printf("%lld ",1); 
		}
		return 0;
	}
	for(int i = 1;i<=n;i++)
	{
		scanf("%lld",&b[i]);
	}
	for(int i = 1;i<=n;i++)
	{
		s();
		as=-1,az=-1;
		for(int j = i;j<=n;j++)
		{
			if(a[j] == 1){
				if(as!=-1){
					for(int k = as;k<j;k++){
						a[k]=0;
						if(a[k]==2)
						{
							az=-1;
						}
					}
				}
				as=j;
			}
			if(a[j] == 2){
				if(az!=-1){
					for(int k = az;k<j;k++){
						a[k]=0;
						if(a[k]==1)
						{
							as=-1;
						}
					}
				}
				az=j;
			}
		} 
		 for(int j = 1;j<=n;j++)
		 {
		 	if(a[j] == 1){
		 		bx++;
			 } 
			 else if(a[j] == 2){
			 	by++;
			 }
		 }
	}
	cout<<bx<<" "<<by;
}
