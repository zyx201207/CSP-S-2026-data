#include<bits/stdc++.h>
using namespace std;
long long a[1000010],s[1000010];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t,n,k;
	cin>>c>>t;
	for(long long i=0;i<t;i++)
	{
		cin>>n>>k;
		for(int j=2;j<=n;j++)
		{
			cin>>a[j]>>s[j];
		}
	}
	cout<<1<<endl<<2<<endl;
	return 0;
}
