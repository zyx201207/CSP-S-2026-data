#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[100005],k,a[10000],t[10000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
	}
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>a[i]>>t[i];
	}
	for(int i=1;i<=q;i++)
	{
		cout<<t[i]+t[i+1]+w[i]<<endl;
	}
	return 0;
}