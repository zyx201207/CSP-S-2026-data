#include<iostream>
#include<cstring>
using namespace std;
#define int long long
int ans1 = 0,c,t,n,d,x[2000005],ans[2005][2005],to[200005],cnt[2005][2005];
void pfs(int m,int c){
	if(to[m]) return;
	to[m] = 1;
	for(int i = m;i <= n;i++){
		if((x[i] - x[m]) <= d){
			ans[m][i] = min(ans[m][i],c+1);
			pfs(i,c+1);
		}
	}
}
void pfs1(int m,int c){
	if(to[m]) return;
	to[m] = 1;
	for(int i = m;i <= n;i++){
		if((x[i] - x[m]) <= d){
			if((c + 1) == ans[m][i]);
			cnt[m][i]++;
			pfs(i,c+1);
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i = 1;i <= t;i++){
		cin>>n>>d;
		for(int i = 1;i <= n;i++){
			cin>>x[i];
		}
		for(int i = 1;i <= n;i++){
			pfs(i,0);
			
		}
		memset(to,0,sizeof(0));
		for(int i = 1;i <= n;i++){
			pfs1(i,0);
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(cnt[i][j] == 2) ans1++;
			}
		}
		cout<<ans1<<endl;
	}
	
	
	return 0;
}

