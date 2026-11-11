#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,i,j,t,ans[300010],a[500010],x,f[300010];
deque<int> q;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++){
		q.clear();
		memset(f,0,sizeof(f));
		for(j=i;j<=n;j++){
			if(!f[a[j]]){
				q.push_back(a[j]);
				f[a[j]]=1;
			}
			if(f[a[j]]!=0){
				while(1){
					x=q.back();
					if(x!=a[j]){
						f[x]=0;
						q.pop_back();
					}
					else{
						f[a[j]]=1;
						break;
					}
				}
			}
		}
		while(!q.empty()){
			x=q.back();
			ans[x]++;
			q.pop_back();
		}
	}
	for(i=1;i<=m;i++) cout<<ans[i]<<" ";
}
