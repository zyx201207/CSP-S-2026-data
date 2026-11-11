#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500005;
const int INF=1e18;
int c,n,m,d,q,ans;
int t[N],a[N],cnt[N],minn[N];
int w[N];
struct Node{
	int k,tt;
};
vector<int > g[500005]; 
vector<int > mp[500005]; 
int dis[5005][5005];
vector<int > sub[505];
void solve(){
	for(int i=0;i<m;i++) for(int j=0;j<m;j++) dis[i][j]=INF;
	for(int k=0;k<m;k++){
		for(int i=k;i<m;i++){
			for(int j=k;j<=i;j++){
				dis[i][k]=min(dis[i][k],g[i][j]+g[j][k]);
				dis[k][i]=dis[i][k];
			}
		}
	}
}
signed main(){
	while(cin>>c){
		cin>>n>>m>>d>>q;
		for(int i=0;i<m;i++)
			cin>>w[i];
		for(int j=0;j<n;j++){
			int k;
			cin>>k; 
			cnt[j]=k;
			memset(t,0,sizeof(t));
			for(int i=0;i<k;i++){
				int aa,tt;
				cin>>aa>>tt;
				t[aa-1]=tt,a[aa-1]=1;
				sub[j].push_back(a[i]);
			}
			for(int i=0;i<m;i++){
				for(int ff=0;ff<m;ff++){
					if(i==ff) continue;
					if(!a[i] or !a[ff]) g[i].push_back(INF);
					else g[i].push_back(t[i]+t[j]);
				}
			}
		}
		for(int i=0;i<m;i++){
			for(int j=0;j<m;j++){
				cout<<g[i][j]<<" ";
			}
			cout<<endl;
		}
		solve();
		for(int i=0;i<m;i++){
			for(int j=0;j<m;j++){
				cout<<dis[i][j]<<" ";
			}
			cout<<endl;
		}
		for(int i=0;i<q;i++){
			int st,de;
			cin>>st>>de;
			if(st==de) cout<<0<<endl;
			else cout<<dis[st-1][de-1]+w[st-1]+w[de-1]<<endl;
		}
	}
	return 0;
}
