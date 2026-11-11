#include<bits/stdc++.h>
using namespace std;
#define N 11101
long long a[N];
long long b[N];
int main()
{
  freopen("card.in","r",stdin);
  freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
	cin>>a[i];
	}
	cout<<n<<" "<<m<<" "<<a[1]<<endl;
 return 0;
}
