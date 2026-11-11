#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,x) for(int i=1;i<=x;i++)
int c,T,n,a[5010],d;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		F(i,n)cin>>a[i];
		int sum=0;
		F(i,n-3){
			int o=0;
			if(a[i+3]-a[i]<=d) continue;
			if(a[i+2]-a[i]<=d&&a[i+3]-a[i+1]<=d) o++;
			if(o) sum++;
		}cout<<sum<<'\n';
	}
	return 0;
}

