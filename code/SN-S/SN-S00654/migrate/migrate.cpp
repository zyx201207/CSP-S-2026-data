#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6+10;
int sid,T,n,m,a[maxn],val1[maxn],val2[maxn],val3[maxn],nxt[maxn],ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>sid>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		nxt[n]=n;
		for(int i=n-1;i>=1;i--){
			nxt[i]=nxt[i+1];
			while(a[nxt[i]]-a[i]>m){
				nxt[i]--;
			}
		}
		ans=0;
		for(int i=n;i>=1;i--){
			val1[i]=0;
			val2[i]=0;
			val3[i]=0;
			if(i==nxt[i]){
				continue;
			}
			ans+=val1[nxt[i]];
			if(i==1){
				break;
			}
			val1[i]+=max(i,nxt[i-1])-max(i,nxt[i-2]);
			val2[i]+=nxt[i]-max(i,nxt[i-1]);
			if(nxt[i]==nxt[i-1]){
				if(nxt[i]!=nxt[i-2]){
					val1[i]+=val2[nxt[i]];
				}
			}
			else if(nxt[i]==nxt[i-1]+1){
				val1[i]+=val3[nxt[i]];
				val2[i]+=val2[nxt[i]];
				val3[i]+=val3[nxt[i]];
			}
			else{
				val1[i]+=val1[nxt[i]];
				val2[i]+=val2[nxt[i]];
				val3[i]+=val1[nxt[i]];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
