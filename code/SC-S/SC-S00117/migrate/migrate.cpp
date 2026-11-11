#include <bits/stdc++.h>
using namespace std;
#define int long long
struct ak{
	int u,l;
};
int n,d,c,t,ab[2000005]={};
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for (int i=1;i<=n;i++){
			cin>>ab[i];
		}
		int sum=0;
		for (int x=1;x<=n;x++){
			for (int y=x+1;y<=n;y++){
				queue<ak>ac;
				ac.push({x,0});
				int ans=1e9,z=0;
				while(!ac.empty()){
					int u=ac.front().u,l=ac.front().l;
					ac.pop();
					if (l>ans)continue;
					if (u==y){
						ans=l;
						z++;
					}
					for (int i=u+1;i<=y;i++){
						if (ab[i]-ab[u]>d||l+1>ans)break;
						ac.push({i,l+1});
					}
				}
				if (z==2){
					sum++;	
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
} 