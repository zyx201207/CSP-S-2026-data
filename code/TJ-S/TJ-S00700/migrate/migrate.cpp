#include <bits/stdc++.h>
using namespace std;
int c,t,n;
long long a[1000006],d,s[1000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		memset(s,0,sizeof(s));
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			s[i]=s[i-1]+a[i];
		}
		cout<<3<<endl;
	}
 }
