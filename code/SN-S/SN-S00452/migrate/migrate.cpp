#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inff=1e18;

int n,m,a[500005],l[500005],r[500005],d[500005],s[500005];
vector<int>e[500005];

void bfs(int y){
	queue<int>que;
	que.push(y);
	while(que.size()){
		int x=que.front();que.pop();
		int ss=e[x].size();
		for(int i=0;i<ss;i++){
			if(d[e[x][i]]>d[x]+1){
				s[e[x][i]]=s[x];
				d[e[x][i]]=d[x]+1;
				que.push(e[x][i]);
			}
			else if(d[e[x][i]]==d[x]+1)s[e[x][i]]+=s[x];
		}
	}
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int ccc,T;
	cin>>ccc>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			e[i].clear();
		}
		for(int i=1;i<=n;i++){
			l[i]=r[i]=i;
			for(int j=20;j>=0;j--){
				if(l[i]-(1<<j)>=1&&abs(a[i]-a[l[i]-(1<<j)])<=m)l[i]-=(1<<j);
				if(r[i]+(1<<j)<=n&&abs(a[i]-a[r[i]+(1<<j)])<=m)r[i]+=(1<<j);
			}
			for(int j=l[i];j<=r[i];j++)e[i].push_back(j);
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				s[j]=0;
				d[j]=inff;
			}
			s[i]=1;d[i]=0;
			bfs(i);
			for(int j=1;j<=n;j++)if(s[j]==2)ans++;
		}
		ans/=2;
		cout<<ans<<endl;
	}
	
	return 0;
}
