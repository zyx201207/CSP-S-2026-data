#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+10;
int c,n,m,d,q;
int k[N];
int z[N];
int minn= 1e9+10;
int dy[4] = {1,0,-1,0};
pair<int,int> s[1111][1111];
int st[1111][1111];
vector<int> vec[N];
void dfs(int x,int y,int r,int sum){
	if(sum>=minn) return;
	if(s[x][y].first==r){
		minn = min(minn,sum);
		return ;
	}
	for(int i = 1; i<= n; i++){
		for(int j = 1; j<=z[i]; j++){
			if(!st[i][j]&&s[i][j].first==s[x][y].first){
				st[i][j] = 1;
				dfs(i,j,r,sum+s[i][j].second);
				st[i][j] = 0;
			}
		}
	}
	for(int i = 0; i<4; i++){
		int ny = y+dy[i];
		if(ny>=1&&ny<=z[x]&&!st[x][ny]){
			st[x][ny] = 1;
			dfs(x,ny,r,sum+s[x][ny].second);
			st[x][ny] = 0;
		}
	}
	
	
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1; i<= m; i++) {
		cin>>k[i];
	}
	for(int i = 1; i<= n; i++) {
		cin>>z[i];
		for(int j = 1; j<=z[i]; j++) {
			cin>>s[i][j].first>>s[i][j].second;
		}
	}
	int sum = 0;
	while(q--){
		for(int i = 1; i<= n; i++) {
			for(int j = 1; j<=z[i]; j++) {
				st[i][j] = 0;
			}
		}
		sum = 0;
		minn = 1e9+10;
		int l,r;
		cin>>l>>r;
		sum = k[l]+k[r];
		for(int i = 1; i<= n; i++) {
			for(int j = 1; j<=z[i]; j++) {
				if(s[i][j].first==l){
					dfs(i,j,r,sum+s[i][j].second);
					
				}
			}
		}
		cout<<minn<<"\n";
	}
	return 0;
}
