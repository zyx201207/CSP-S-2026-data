#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5,M=6;
int n,m,ans;
int a[N];
/*int trie[N*M+N][2],cnt[N*M+N],tot;
void add(int a){
	int u=0;
	for(int i=M;i>=0;i--){
		int id=(a>>i)&1;
		if(!trie[u][id])trie[u][id]=++tot;
		u=trie[u][id];
		cnt[u]++;
	}
}*/
void dfs(int i,int cnt,int sum){
	if(cnt==m){
		ans=max(ans,sum);
		return;
	}for(int j=i+1;j<=n;j++){
		dfs(j,cnt+1,sum&a[j]);
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		//add(a[i]);
	}dfs(0,0,(1<<30)-1);
	cout<<ans;
/*	int u=0,sum=(1<<M)-1,cnl=0;
	for(int i=M;i>=0;i--){
		if(i!=M&&!u)break;
		if(cnl==m)break;
			if(cnt[trie[u][1]]<=m-cnl){
				int y=(1<<i-1);
				int l=i;
				int p=trie[u][1];
				while(1){
					if(trie[p][0]){
						p=trie[p][0];
					}else{
						y+=(1<<l-1);
						p=trie[p][1];
					}if(p)break;
					l--;
				}cnl+=cnt[trie[u][1]];
				sum&=y;
				cout<<"0 "<<y<<' '<<cnt[trie[u][1]]<<'\n';
				u=trie[u][0];
			}else {
				u=trie[u][1];
				cout<<"1\n";
			}
			//cout<<u<<'\n';
	}cout<<sum;     */                                                                                                                                                                                                                            
	return 0;
}
