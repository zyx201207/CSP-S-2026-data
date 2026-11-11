#include<iostream>
#define endl '\n'
using namespace std;
int a[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		if(n%2==0)cout<<n/2;
		else cout<<n/2+1;
	}
	return 0;
 } 
