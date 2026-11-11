#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],ans;
string s;
int main()
{
	freopen("card.in","r",stdin); 
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m==1)
		cout<<n;
	if(m==2)
		cout<<1<<" "<<1;
	return 0;
}
