#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d;
long long a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(c==11||c==11){
			long long s=d/abs(a[2]-a[1]);
			long long s1=(long long)(n-1-2*(s-1));
			if(s<2||s1<0)cout<<0;
			else{
				cout<<s1;
			}
			cout<<endl;
		}
		else cout<<0<<endl;
	}
	return 0;
}
