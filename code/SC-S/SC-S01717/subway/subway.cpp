#include <bits/stdc++.h>
#define int long long
using namespace std;
int rd(){
	int w = 0 , f = 1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f = -1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9') w=(w<<3)+(w<<1)+(ch&15),ch=getchar();
	return w*f;
}
void wt(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) wt(x/10);
	putchar(x%10+'0');
}
const int N = 515 , M = 5e5+15;
vector <pair<int,int> > e[M];
int c,n,m,d,q,f[N][N],w[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=rd(),n=rd(),m=rd(),d=rd(),q=rd();
	memset(f,0x3f,sizeof(f));
	for(int i = 1 ; i<=n ; i++) f[i][i]=0;
	for(int i = 1 ; i<=m ; i++) w[i]=rd();
	for(int i = 1 ; i<=n ; i++){
		int k=rd();
		for(int j = 1,a,t ; j<=k ; j++){
			a=rd(),t=rd();
			e[a].emplace_back(make_pair(i,t));
		}
	}
	for(int i = 1 ; i<=m ; i++){
		for(int j = 0 ; j<(int)e[i].size() ; j++){
			for(int k = j+1 ; k<(int)e[i].size() ; k++){
				int x=e[i][j].first,y=e[i][k].first;
				f[x][y]=f[y][x]=min(f[x][y],e[i][j].second+e[i][k].second);
			}
		}
	}
	for(int k = 1 ; k<=n ; k++){
		for(int i = 1 ; i<=n ; i++){
			for(int j = 1 ; j<=n ; j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		int x=rd(),y=rd(),ans=1e18;
		for(auto i : e[x]){
			for(auto j : e[y]){
				ans=min(ans,w[x]+w[y]+i.second+j.second+f[i.first][j.first]);
			}
		}
		wt(ans),putchar('\n');
	}
	return 0;
}