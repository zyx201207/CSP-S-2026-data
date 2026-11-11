#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10,M=550;
int n,d;
int a[N],dr[N],dl[N],ans,id[N],cnt[N],ss;
void dfs2(int x,int e,int ste){
	//cout<<x<<" "<<e<<endl;
	if(x>e || ste>ss) return ;
	if(x==e){
		ss=min(ss,ste);
		cnt[ste]++;
		return ;
	}
	int u=a[x]+d;
	for(int i=x+1;a[i]<=u && i<=n;i++){
		dfs2(i,e,ste+1);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				memset(cnt,0,sizeof(cnt));
				ss=LONG_LONG_MAX;
				dfs2(i,j,0);
				if(cnt[ss]==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/

