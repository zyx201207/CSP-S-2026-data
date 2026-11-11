#include <iostream>
#include <cstring>

using namespace std;

const int N=500005;
int n,m;
int a[N];
bool vis[N];
int typ[N];
int q[N];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=m;i++){
		memset(vis,0,sizeof(vis));
		memset(q,0,sizeof(q));
		int qxb=1;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0){
				vis[a[j]]==1;
				q[qxb]=a[j];
				qxb++;
			}else{
				int xb=1;
				while(q[xb]!=a[j]){
					xb++;
				}
				xb++;
				while(q[xb]!=0 && xb<=n){
					vis[q[xb]]=0;
					q[xb]=0;
					xb++;
				}
			}
		}
		for(int i=1;i<=m;i++){
			if(vis[i]==1){
				typ[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout << typ[i] << ' ';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
