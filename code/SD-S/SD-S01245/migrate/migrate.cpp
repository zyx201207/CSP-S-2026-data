#include<bits/stdc++.h>
using namespace std;
//bool _st;
const int N=2e6+100;
long long t,n,d,c,ans;
long long x[N],f[N],cnt[N];
bool tt[N];
vector<int> ve[N];
queue<long long> q;
//bool _ed;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
//	cerr<<abs(&_st-&_ed)/1024.0/1024<<" MB\n";
	for(int o=1;o<=t;o++){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			for(int j=1;j<i;j++){
				if(x[i]-x[j]<=d){
					ve[j].push_back(i);
					ve[i].push_back(j);
				}
			}
		}
//		int cn=0;
//		for(int i=1;i<=n;i++){
//			if(ve[i].size()==n-1){
//				cn++;
//			}
//		}
//		if(cn==1){
//			
//		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				f[j]=1e18;
				cnt[j]=0;
				tt[j]=0;
			}
			q.push(i);
			f[i]=0;
			tt[i]=1;
			cnt[i]=1;
			while(!q.empty()){
				long long x=q.front();
				q.pop();
				tt[x]=0;
				for(auto it:ve[x]){
					if(it<i){
						continue;
					}
					if(f[it]==f[x]+1){
						cnt[it]++;
						if(tt[it]==0)q.push(it);
						tt[it]=1;
					}
					else if(f[it]>f[x]+1){
						cnt[it]=cnt[x];
						f[it]=f[x]+1;
						if(tt[it]==0)q.push(it);
						tt[it]=1;
					}
				}
			}
			for(int j=i+1;j<=n;j++){
				ans+=(cnt[j]==2);
			}
		}
		cout<<ans<<"\n";
		for(int i=1;i<=n;i++){
			ve[i].clear();
		}
	}
	return 0;
}
//t 2e5
//n 2e6 ºÍ 2e6
//d 1e18 x +-1e18 
