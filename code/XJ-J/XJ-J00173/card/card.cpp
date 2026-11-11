#include<bits/stdc++.h>
using namespace std;
int a[500005],ans[300005];
struct node{
	int t,w;
};
node b[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=m;i>=1;i--) cout<<a[i];
	return 0; 
}
//Trick||Treat!
