#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
int n,m,a;
cin>>n>>m;
for(int i=1;i<=n;i++)
{
	cin>>a;
	if(a%m==1)
	{
		cout<<m<<" "<<a<<" "<<n;
		return 0;}
	}
return 0;
}
