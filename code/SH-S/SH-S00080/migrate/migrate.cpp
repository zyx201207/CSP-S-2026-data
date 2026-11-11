#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,x[2000010],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for (int i=0;i<t;++i){
		ans=0;
		cin>>n>>d;
		for (int j=1;j<=n;++j){
			cin>>x[j];
		}
		for (int j=1;j<n-1;++j){
			for (int k=j+2;k<=n;++k){
				if (x[k]-x[j]==(2*d-1)){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
