#include<bits/stdc++.h>
using namespace std;

int c, t, n, k, ans;
int a[4002][4002], dis[4002];
int fa[4002];
bool chosen[4002], vis[4002];

void init(){
	for(int i=1;i<=n;i++){
		fa[i]=0; vis[i]=false; chosen[i]=false;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=0;
		}
	}
}

int dist(int x){
	if(chosen[x]) return 0;
	int minn=2147483647;
	for(int i=1;i<=n;i++){
		if(a[x][i]==1&&!vis[i]){
			vis[i]=true;
			minn=min(minn, dist(i)+1);
			vis[i]=false;
		} 
	}
	return minn;
}

int block(){
	int fa[4002];
	memset(fa, 0, sizeof(fa));
	for(int i=1;i<=n;i++){
		if(chosen[i]){
			fa[i]=i;
			for(int j=1;j<=n;j++){
				if(chosen[j]&&i!=j){
					if(a[i][j]==1){
						fa[j]=i;
						while(fa[j]!=fa[fa[j]]) fa[j]=fa[fa[j]];
					}
				}
			}
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		if(chosen[i]&&fa[chosen[i]]==chosen[i]) sum++;
	}
	return sum;
}

void dp(int i, int p){
	int s=block();
	if(s>2||i+p>n) return;
	if(s==2&&p==0){
		int maxn=-1;
		for(int q=1;q<=n;q++){
			int p=dist(q);
			if(p>maxn) maxn=p;
		}
		if(maxn<ans) ans=maxn;
		return;
	}
	for(int k=i+1;k<=n;k++){
		chosen[k]=true;
		dp(k, p-1);
		chosen[k]=false;
		dp(k, p);
	}
}

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	cin>>c>>t;
	
	while(t--){
		ans=2147483647;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int x, y;
			cin>>x>>y;
			a[x][y]=1; a[y][x]=1;
		}
		for(int i=1;i<=n;i++){
			dp(i, k);
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
