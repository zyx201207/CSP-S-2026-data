#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	int c,T;
	cin>>c>>T;
	while(T--){
		int n,d;
		cin>>n>>d;
		vector<int>v;
		
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			v.push_back(x);
		}
		int ans=0;
		for(int i=0;i<n;i++){
			
			vector<int>vis(n,0);
			for(int j=i;j<n;j++){
				int xb=0;
				
				while((v[j]+d)>=v[j+xb]&&j+xb<n){
					if(xb){
						vis[j+xb]++;
//						cout<<vis[j+xb]<<" "<<j+xb<<endl;
					}
//					
					xb++;
					
				} 
			}
			for(int j=i;j<n;j++){
//				cout<<vis[j]<<" "<<j<<endl;
				if(vis[j]==2){
					ans++;
				}
			}
		}
		cout<<ans/3<<'\n';
	}
} 
