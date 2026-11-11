#include <bits/stdc++.h>//不完整 收牌的特判还没有判 
#define int long long
using namespace std;
const int mn=5e5+10,nm=3e5+10;
int n,m;
int a[mn],ans[mn];
bool dis[nm];
queue <int> q;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(dis[a[j]]==0){//没有点数就加入 
				q.push(a[j]);
				dis[a[j]]=1;
			}else{//有点数要开始收牌 
				while(q.front()!=a[j]){
					dis[q.front()]=0;
					q.pop();
				}
				dis[a[j]]=1;
				q.push(a[j]);
			}
		}
		for(int j=1;j<=m;j++){
			if(dis[j]==1) ans[j]++;
		}
	}
	for(int i=1;i<=m;i++) cout << ans[i] << " ";
	return 0;
}
