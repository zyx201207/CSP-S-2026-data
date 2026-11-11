#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
bool dis[600][600],flag[600];
struct station{
	int _zhanting;
	int zhanting_zhantai=0x3f3f3f3f;
}a[510];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> a[i]._zhanting;
	}
	for(int i=1;i<=n;i++){
		int k,b[600];
		cin >> k;
		for(int j=1;j<=k;j++){
			int t;
			cin >> b[j] >> t;
			a[b[j]].zhanting_zhantai=min(a[b[j]].zhanting_zhantai,t);
			dis[b[j]][b[j-1]]=1;
			dis[b[j-1]][b[j]]=1;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin >> x >> y;
		int ans=a[x]._zhanting+a[x].zhanting_zhantai;
		queue <int> q;
		for(int j=1;j<=n;j++){
			if(dis[x][j]==1){
				q.push(j);
				flag[x]=1;
			}
		}
		while(!q.empty()){
			int r=q.front();
			q.pop();
			if(r==y){
				ans+=a[y]._zhanting;
				break;
			}
			for(int j=1;j<=n;j++){
				if(dis[r][j]==1){
					q.push(j);
					ans+=a[r].zhanting_zhantai;
					flag[j]=1;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
