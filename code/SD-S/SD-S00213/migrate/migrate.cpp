#include <bits/stdc++.h>
#define int long long 
using namespace std;
int c,t,n,d,a[100005],cnt;
void dfs(int st,int outi,int ct,int Co){
	if(st==outi+1){
		if(ct==Co) cnt++;
		return ;
	}
	for(int i=1;i<=d;i++){
		dfs(st+i,outi,ct+1,Co);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				cnt=0;
				int Co=ceil(1.0*(i-j)/d);
				if(j+Co>=i) dfs(j,i,0,Co);
				if(cnt==2) ans++;//2¶Ô
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
