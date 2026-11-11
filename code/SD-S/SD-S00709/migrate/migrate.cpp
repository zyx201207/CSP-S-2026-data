#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
const int INF=1e18;
int c,t;
int n,d;
int x[N];
vector<int> seq;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int ans=0;
		for(int u=1;u<=n;u++){
			for(int v=u+1;v<=n;v++){
				if(u==v){
					continue;
				}
				int len=v-u-1;
				int res=INF;
				for(int s=0;s<(1<<len);s++){
					seq.clear();
					seq.push_back(u);
					for(int i=1;i<=len;i++){
						if(s&(1<<(i-1))){
							seq.push_back(u+i);
						}
					}
					seq.push_back(v);
					bool flag=1;
					int cnt=0;
					for(int i=0;i<seq.size()-1;i++){
						int a=seq[i],b=seq[i+1];
						if(abs(x[a]-x[b])>d){
							flag=0;
							break;
						}
						cnt++;
					}
					if(flag){
						res=min(res,cnt);
					}
				}
				int tot=0;
				for(int s=0;s<(1<<len);s++){
					seq.clear();
					seq.push_back(u);
					for(int i=1;i<=len;i++){
						if(s&(1<<(i-1))){
							seq.push_back(u+i);
						}
					}
					seq.push_back(v);
					bool flag=1;
					int cnt=0;
					for(int i=0;i<seq.size()-1;i++){
						int a=seq[i],b=seq[i+1];
						if(abs(x[a]-x[b])>d){
							flag=0;
							break;
						}
						cnt++;
					}
					if(flag){
						if(cnt==res){
							tot++;
						}
					}
				}
				if(tot==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
