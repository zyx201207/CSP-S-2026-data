#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,T,n,ans=0,r;
int f[N],g[N];
long long a[N],d;
int cnt[N];
vector<int> out[N];
priority_queue<int,vector<int>,greater<int>> p;
priority_queue<int,vector<int>,greater<int>> q;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		ans=0;bool o=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>2)o=o&&(a[i]-a[i-1]==a[i-1]-a[i-2]);
		}
		if(o&&n>2){
			long long t=d/(a[2]-a[1]);
			if(t==1)cout<<0<<'\n';
			else{
				cout<<(n-t*2+1);
			} 
			continue ;
		}
		for(int i=1;i<=n;i++){
			r=i;
			while(!p.empty())p.pop();
			while(!q.empty())q.pop();
			p.push(0);
			for(int j=0;j<=n;j++)cnt[j]=0;
			cnt[0]=1;
			for(int j=i;j<=n;j++)out[j].clear();
			out[i+1].push_back(0);
			for(int j=i;j<=n;j++){
				int l=out[j].size();
				for(int k=0;k<l;k++)
					q.push(out[j][k]);
				out[j].clear();
				while(!p.empty()&&!q.empty()&&p.top()==q.top()){
					cnt[p.top()]--;p.pop();q.pop();
				}
				while(a[r+1]-a[j]<=d&&r<=n)r++;
				if(!p.empty()){
					int x=p.top();
					if(cnt[x]==2)ans++;
					if(cnt[x]>2)continue ;
					for(int k=0;k<cnt[x];k++){
						p.push(x+1);
						cnt[x+1]++;
						out[r+1].push_back(x+1);
					}
				}
				else break ;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}