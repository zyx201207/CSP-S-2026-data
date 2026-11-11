#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5,M=3e5+5;
int n,m,a[N],p[M],k[N],cnt;
bool vis[N];
unordered_map<int,int> mp;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		cnt=0;
		memset(k,0,sizeof k);
		memset(vis,0,sizeof vis);
		mp.clear();
		for(int j=i;j<=n;j++){
			if(cnt==0||mp.find(a[j])==mp.end()||vis[mp[a[j]]]){
				k[++cnt]=a[j];
				mp[a[j]]=cnt;
			}
			else{
				int t=mp[a[j]];
				for(int u=t;u<=cnt;u++){
					vis[u]=1;
				}
				k[++cnt]=a[j];
				mp[a[j]]=cnt;
			}
		}
		for(int j=1;j<=cnt;j++){
			if(!vis[j]){
				p[k[j]]++;
			}
		}
	}
	for(int j=1;j<=m;j++){
		cout<<p[j]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
