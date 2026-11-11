#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define PII pair<int,int>
const int N=5e3+5,mod=1e9+7;
int n,m,q,T,c,d;
int a[N],dp[N];
int jump1[N];
int find1(int l,int r,int k){
	int ans=l;
	while(l<=r){
		int mid=(l+r)>>1;
		if(a[mid]>k){r=mid-1;
		}else{l=mid+1;ans=mid;}
	}return ans;
}
int edge[N][N];
int cnt[N][N],ans;
void bfs(int s){
	queue<int>q;
	q.push(s);
	cnt[s][s]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int v=u+1;v<=jump1[u];v++){
			if(cnt[s][v]){
				if(edge[s][u]+1==edge[s][v]){//记录新节点同样处于最短路的次数 
					cnt[s][v]+=cnt[s][u];
				}
			}else{
				edge[s][v]=edge[s][u]+1;
				cnt[s][v]+=cnt[s][u];
				q.push(v);
			}
		}
	}
}
void solve(){
	for(int i=1;i<=n;i++){
		jump1[i]=min(find1(i,n,a[i]+d),n);
		for(int j=i+1;j<=jump1[i];j++){
			edge[i][j]=1;
		}
//		cout<<jump1[i]<<" ";
	}
//	cout<<"\n";
	ans=0;
	for(int i=1;i<=n;i++){
		bfs(i);
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
//			cout<<cnt[i][j]<<" ";
			if(cnt[i][j]==2){
				ans++;
			}
		}
//		cout<<"\n";
	}
	cout<<ans<<"\n";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			edge[i][j]=cnt[i][j]=0;
		}
	}
}
signed main(){
	ios;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c<=10){
			solve();
		}else if(c<=12){
			if(a[2]-a[1]>d){
				cout<<0<<"\n";
				continue;
			}
			solve();
		}else if(c<=14){
			cout<<0<<"\n";
		}else{
			solve();
		}
	}
	return 0;
}

