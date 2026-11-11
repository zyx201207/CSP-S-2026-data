#include<bits/stdc++.h>
using namespace std;

int n,m;
const int N=5005;

int a[N];
int ans[N];
int table[2*N];
bool vis[3005],pre[3005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if(m==1){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(table,0,sizeof table);
		memset(vis,0,sizeof vis);
		memset(pre,0,sizeof pre);
		int e=0;
		for(int j=i;j<=n;j++){
			e++;
			table[e]=a[j];
			if(vis[table[e]]){
				int p=pre[table[e]];
				for(int k=p+1;k<e;k++){
					vis[table[k]]=0;
					pre[table[k]]=0;
				}
				e=p;
			}
			pre[table[e]]=e;
			vis[table[e]]=1;
		}
		/*for(int j=1;j<=e;j++) cout<<table[j]<<" ";
		cout<<"\n";	*/	for(int j=1;j<=e;j++) ans[table[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}