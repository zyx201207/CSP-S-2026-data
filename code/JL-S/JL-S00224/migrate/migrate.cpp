#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,T,a[5000005],d,n;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		if(n<4){
			cout<<0<<endl;
			continue;
		}for(int i=1;i<=n;i++){
			cin>>a[i];
		}sort(a+1,a+n+1);
		int s=0;
		for(int i=0;i<=n-4;i++){
			if(a[i+3]-a[i+1]<=d&&d<a[i+4]-a[i+1]&&a[i+4]-a[i+2]<=d)s++;
		}cout<<s<<endl;
	}return 0;
}
