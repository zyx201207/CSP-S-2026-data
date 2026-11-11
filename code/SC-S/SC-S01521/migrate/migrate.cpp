#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[2000005],dist[2000005],s[2000005],ans;
vector<int>v[2000005];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			v[i].clear();
		}
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d){
					v[i].push_back(j);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[j]=1e18;
				s[j]=0;
			}
			dist[i]=0;
			s[i]=1;
			for(int j=i;j<=n;j++){
				if(s[j]==2){
					ans++;
				}
				for(int k:v[j]){
					if(dist[k]>dist[j]+1){
						dist[k]=dist[j]+1;
						s[k]=s[j];
					}else if(dist[k]==dist[j]+1){
						s[k]+=s[j];
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}