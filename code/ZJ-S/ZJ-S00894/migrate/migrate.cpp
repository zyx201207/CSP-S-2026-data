#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e6+10,M=5e5+10;
int c,t,n,d,ans;
int f[N],cnt[N],x[N];
void dfs(int i,int k){
	for(int j=i;j<=n;j++){
		if(x[j]-x[i]<=d){
			if(k+1<cnt[i]){
				cnt[i]=k+1;
				dfs(j,k+1);
			}else{
				f[i]++;
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		int flag=1;cin>>n>>d;
		memset(cnt,0x3f,sizeof(cnt));
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(x[i]-x[i-1]>d) flag=0; 
		}
		if(n<=5000){
			for(int i=1;i<=n;i++){
				dfs(i,0);
			}
			for(int i=1;i<=n;i++){
				if(f[i]==2) ans++;
			}
			cout<<ans<<'\n';
		}
		else if(flag){cout<<"0\n";continue;}
		else{cout<<n/2<<"\n";continue;}
		
	}
	return 0;
}