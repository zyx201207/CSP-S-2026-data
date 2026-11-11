#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+7;
int a[maxn],c,t,d,n;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;++i){
			cin>>a[i];
			//diff[i]+diff[i-1]=a[i]-a[i-1]-a[i-1]-a[i-2]=a[i]-a[i-2]
		}
		int cnt=0;
//		cout<<endl;
//		for(int i=1;i<=n;++i){
//			cout<<diff[i]<<' ';
//		}
//		cout<<endl;
//		for(int i=1;i<=n;++i){
//			cout<<sum[i]<<' ';
//		}
		for(int l=1;l<=n;++l){
			for(int r=l+1;r<=n;++r){
				if(a[r]-a[l]==d+1&&r-l>1){
//					cout<<endl<<r<<' '<<l<<endl;
					if(d<=2||r-l<=d)
						cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/

