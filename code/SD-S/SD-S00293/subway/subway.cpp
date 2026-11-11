#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,n,m,d,q;
const int N = 505;
const int M = 5e5+5; 
int w[M],k[N],t[N][N],a[N][N],x[N],y[N];
int ans = 0;
int tt[N];
map<pair<int,int>,int> mp;
void dfs(int cur,int ed,int sum,bool ok,int l,string s){
	if(cur == ed && ok == 1){
		sum += t[l][cur];
		if(ans == 0)ans = sum;
		else ans = min(ans,sum);
		//到达了ed号地铁站 
		return ; 
	} 
	if(ok == 0){
		//不换乘，继续往前走 
		for(int j=1;j<k[l];j++){
			if(a[l][j] == cur){
				dfs(a[l][j+1],ed,sum,1,l,s);
				dfs(a[l][j+1],ed,sum,0,l,s);
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(i == l)continue;
			for(int j=1;j<=k[i];j++){
				pair<int,int> tmp= make_pair(i,cur);
				int lst = tt[cur];
				if(mp.find(tmp) == mp.end() || mp[tmp] == 0){
					mp[tmp] = 1;
					tt[cur]++;
				}
				else mp[tmp]++;
				if(a[i][j] != cur)continue;
				int tp = a[i][j];
				int pre = sum;
				if(l == 0)sum = sum + t[i][tp];
				else sum = sum + t[i][tp]+t[l][cur];
				dfs(cur,ed,sum,0,i,s+char(cur+'0'));
				if(lst<tt[cur])tt[cur]--;
				sum = pre;
				mp[tmp]--;
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];
			int tmp = a[i][j];
			cin>>t[i][tmp];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++){
		int st = x[i],ed = y[i];
		ans = 0;
		dfs(st,ed,0,1,0,"");
		cout<<ans+w[st]+w[ed]<<"\n";
	}
	return 0;
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2
//_______
//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4
//2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7
//1 6
//2 3 
