#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[2000005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
		ans+=w[i];
	}
	
	for(int i=1;i<=q;i++)
	{
		
		cout<<ans-w[m-1]<<endl;
	}
	return 0;
}
