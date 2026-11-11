#include <bits/stdc++.h>
#define int long long
#define N 2000008
using namespace std;
int C,T;
int x[N];
set<pair<int,int> > s,s2;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>C>>T;
	while(T--){
		int n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(x[j]-x[i]<=d&&x[k]-x[j]<=d){
						if(s.count({i,k})){
							if(!s2.count({i,k})){
								s2.insert({i,k});
								ans++;
							}
							else{
								ans--;
							}
						}
						else{
							s.insert({i,k});
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

