#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m,a[N],ans[M],v[N],cnt;
bool vis[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,false,sizeof vis);
		cnt=0;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				while(v[cnt]!=a[j]){
					vis[v[cnt]]=false;
					cnt--;
				}
			}else{
				v[++cnt]=a[j];
				vis[a[j]]=true;
			}
		}
		for(int i=1;i<=cnt;i++){
			ans[v[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0; 
}
