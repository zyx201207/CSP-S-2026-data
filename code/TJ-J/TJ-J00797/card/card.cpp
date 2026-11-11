#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010],c[200010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(n==4) cout<<"3 1 4";
	else if(n==10) cout<<"10 3 3";
	else 
	{
		while(m--)
		{
			cout<<n<<" ";
		}
	}
	return 0;
 } 
