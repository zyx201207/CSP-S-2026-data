#include<bits/stdc++.h>
using namespace std;
long long b[300005];
long long n,m,a[500005],ans[300005];
int main(){freopen("card.in","r",stdin);freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	cout<<n<<" "<<m/2-1<<" "<<n/2+1;
	return 0;
}

