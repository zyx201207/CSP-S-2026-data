#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+10;
int c,t,n,d,x[N];
//vector <vector<int> > dis;
bool dis[N][N];
int cnt[N];
int res,minstep=INT_MAX;
//长度最短 说明至少有 
void initdis(){
	for (int i=1;i<n;i++){
		for (int j=i+1;j<=n;j++){
//			if (i==j)	dis[i][j]==0;
//			dis[i][j]=abs(x[i]-x[j]);
			if(abs(x[i]-x[j])<=d)	dis[i][j]=true;
		}
	}
}
void dfs(int u,int v,int step,int cur){
	for (int i=1;dis[cur][cur+i]==true;i++){
		if (cur+i==v){
			cnt[step+1]++;
//			minstep=min(minstep,step+1);
			return ;
		}
//		if (step+1>=minstep)	return ;
		dfs(u,v,step+1,cur+i);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> c >> t;
	while (t--){
		minstep=INT_MAX;
		res=0;
		memset(dis,0,sizeof(dis));
		cin >> n >> d;
		for (int i=1;i<=n;i++)
			cin >> x[i];
		initdis();
//		for (int i=1;i<=n;i++){
//			for (int j=1;j<=n;j++){
//				cout << dis[i][j] << " ";
//			}
//			cout << endl;
//		}
		for (int u=1;u<=n-1;u++){
			for (int v=u+1;v<=n;v++){
				dfs(u,v,0,u);
//				int i=1;
				for (int i=1;i<=v-u+1;i++){
//					cout << cnt[i] << " ";
					if (cnt[i]!=0){
						if (cnt[i]==2)	res++;
						break;
					}
				}
//				cout << endl;
				memset(cnt,0,sizeof(cnt));
			}
		}
		cout << res << endl;
	}
	
	return 0;
}

