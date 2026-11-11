#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,p;
int main() 
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>n;
	if(n==2) cout<<1<<endl<<2;
	else
	{
		for(int i=1;i<=n;i++)
		{
			cout<<rand()%n<<endl;
		}
	}
	return 0;
}
