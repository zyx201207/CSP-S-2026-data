#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,m,a[100000],e[100000],ans[100000];
bool d[100000],vis[100000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(e,0,sizeof(e));
		memset(d,false,sizeof(d));
		memset(vis,true,sizeof(vis));
		for(int j=i;j<=n;j++){
			if(d[a[j]]==true){
				for(int k=e[a[j]];k<j;k++){
					if(vis[k]==false){
						continue;
					}
					ans[a[k]]--;
					d[a[k]]=false;
					e[a[k]]=0;
					vis[k]=false;
				}
				ans[a[j]]++;
				e[a[j]]=j;
			}
			else{
				d[a[j]]=true;
				e[a[j]]=j;
				ans[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

