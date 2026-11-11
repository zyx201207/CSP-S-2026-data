#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2222222],sum;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		sum=0;
		for(int l=1;l<=n;l++){
			for(int r=l+1;r<=n;r++){
				if((x[r]-x[l])/d!=0&&(x[r]-x[l])%d!=0){
					sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
