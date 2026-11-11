#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d;
int a[2000006];
vector<int>to[5003];
int dis[5003][5003];
int cnt[5003][5003];
bool v[5003];
void bfs(int s){
	queue<int>q;
	for(int i=1;i<=n;i++){
		dis[s][i]=0x3f3f3f3f3f3f3f3f;
		cnt[s][i]=0;
		v[i]=0;
	}
	dis[s][s]=0;
	q.push(s);
	cnt[s][s]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		if(v[x])continue;
		v[x]=1;
		for(int y:to[x]){
			int w=1;
			if(dis[s][x]+w<dis[s][y]){
				dis[s][y]=dis[s][x]+w;
				cnt[s][y]=0;
				q.push(y);
			}
			if(dis[s][x]+w==dis[s][y]){
				cnt[s][y]+=cnt[s][x];
			}
		} 
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n==1||d==0){
			cout<<"0\n";
			continue; 
		}
		int c=a[2]-a[1];
		bool f=1;
		for(int i=3;i<=n;i++){
			if(a[i]-a[i-1]!=c){
				f=0;
				break;
			}
		}
		if(f){
			d=d/c;
			int len=(d<=1?n+1:2*d);
			cout<<max(0ll,n-len+1)<<"\n";
			continue;
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(a[i]-a[j])<=d){
					to[i].push_back(j);
					to[j].push_back(i);
				}
			}
		}
		for(int i=1;i<=n;i++){
			bfs(i);
		}
		/*
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(dis[i][k]+dis[k][j]<dis[i][j]){
						dis[i][j]=dis[i][k]+dis[k][j];
						cnt[i][j]=0;
					}
					if(dis[i][k]+dis[k][j]==dis[i][j]){
						cnt[i][j]++;
					}
				}
			}
		}*/
		
		int ans=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans+=(cnt[i][j]==2);
			}
		}
		for(int i=0;i<=n;i++){
			to[i].clear();
		}
		cout<<ans<<"\n";
	} 
	
	return 0; 
}
/*
1~6 n^3 24
A:8 
能飞过i(i>1)个贡献2i长度的序列 
 
*/
