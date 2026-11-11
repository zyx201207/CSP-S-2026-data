#include <iostream>
#include <vector>
using namespace std;
#define ll long long
//head

int n,m,a[500010];
vector<int> pos[300010];
int nxt[500010];
ll ans[300010];
//val

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pos[a[i]].push_back(i);
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<pos[i].size()-1;j++){
			nxt[pos[i][j]]=pos[i][pos[i].size()-1];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(nxt[j]){
				j=nxt[j];
			}
			ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	
	return 0;
}
