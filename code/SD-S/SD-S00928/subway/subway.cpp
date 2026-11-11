#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long a[500010];
long long dist[510][510];
priority_queue<pair<int,long long>,vector<pair<int,long long> >,greater<pair<int,long long> > > p[510];
vector<pair<int,long long> > p2[510],ans[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) cin >> a[i];
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dist[i][j]=1e9+1;
	for(int i=1;i<=n;i++){
		int k,v,t;
		cin >> k;
		for(int j=1;j<=k;j++){
			cin >> v >> t;
			p[i].push({v,t});
			ans[v].push_back({i,t});
		}
		for(int j=1;j<=k;j++){
			p2[i].push_back(p[i].top());
			p[i].pop();
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int l1=0,l2=0,r1=p2[i].size()-1,r2=p2[j].size()-1;
			while(1){
				if(l1>r1||l2>r2) break;
				long long cnt1=p2[i][l1].second,cnt2=p2[j][l2].second;
				int e1=p2[i][l1].first,e2=p2[j][l2].first;
				if(e2==e1) l1++,l2++,dist[i][j]=dist[j][i]=min(dist[i][j],cnt1+cnt2);
				else if(l1==r1&&l2==r2) break;
				else if(e1<e2) l1++;
				else l2++; 
			}
		}
	}
	for(int c=1;c<=n;c++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(c==i||c==j||i==j) continue;
				dist[i][j]=min(dist[i][j],dist[i][c]+dist[j][c]);
			}
		}
	}
	for(int i=1;i<=n;i++) dist[i][i]=0;
	for(int c=1;c<=q;c++){
		int l,r;
		long long minn=1e9+1;
		cin >> l >> r;
		for(int i=0;i<=ans[l].size()-1;i++){
			for(int j=0;j<=ans[r].size()-1;j++){
				long long ans1=ans[l][i].second,ans2=ans[r][j].second;
				int e1=ans[l][i].first,e2=ans[r][j].first;
				minn=min(minn,ans1+ans2+dist[e1][e2]);
			}
		}
		cout << minn+a[l]+a[r] << endl;
	} 
	return 0;
}

