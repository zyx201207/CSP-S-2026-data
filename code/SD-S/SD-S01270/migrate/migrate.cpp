#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2E6+3;
int a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		bool flag=1;
		int q,w,ans=0;
		cin>>q>>w;
		for(int i=1;i<=q;i++){
			cin>>a[i];
		}int g=a[q]-a[q-1];
		for(int i=2;i<=q;i++){
			if(a[i]-a[i-1]!=a[q]-a[q-1]){
				flag=0;
			}
		}if(flag==1){
			if(2*g>w){
				ans=0;
			}if(w>=3*g){
				ans=0;
			}if(w<3*g&&w>=2*g){
				ans=q-3;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}


