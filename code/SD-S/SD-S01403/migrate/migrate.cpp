#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,d,x[2000005]={},flag1=1;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t>>t;
	while(t--){
		cin>>n>>d;
		int gc;
		cin>>x[1]>>x[2];
		gc=x[2]-x[1];
		for(int i=3;i<=n;i++){
			cin>>x[i];
			if(x[i]-x[i-1]!=gc){
				flag1=0;
			}
		}
		if(flag1){
			if(x[3]-x[1]<=d){
				cout<<n-3<<endl;
			}else{
				cout<<0;
			}
		}else{
			vector<vector<int>>ar(n+1);
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(abs(x[i]-x[j])<=d){
						ar[i].push_back(j);
						ar[j].push_back(i);
					}
				}
			}
			cout<<0;
		}
	}
	return 0;
}
