#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int T,n,d,mo,a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>mo>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;++i)cin>>a[i];
		bool flag=1;
		for(int i=3;i<=n;++i)if(a[i]-a[i-1]!=a[i-1]-a[i-2])flag=0;
		if(flag==1){
			if(a[2]-a[1]>d)cout<<0<<'\n';
			else cout<<max(n-3,0)<<'\n';
			continue;
		}
		int cnt=0;
		for(int i=1;i<=n;++i){
			for(int j=i+3;j<=n;++j){
				if(a[j]-a[i]<=d)continue;
				for(int k=i+1;k<=j-1;++k){
					if(a[k]-a[i]<=d && a[j]-a[k]<=d)cnt++;
				}
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
