#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+7;
int n,m;
int a[N];
bool flag=false;
int ans[N];
bool vis[N];
unordered_map <int,int> mp;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		memset(vis,0,sizeof(vis));
		mp.clear();
//		cout<<mp.size()<<endl;
		for(int j=i;j<=n;j++){
			mp[a[j]]++;
			if(mp[a[j]]%2==0){
//				cout<<j<<endl;
				vis[j]=true;
				for(int z=j-1;z>=i;z--){
					if(vis[z]) continue;
					if(a[z]==a[j]&&vis[z]==false){
						vis[z]=true;
						break;
					}
					vis[z]=true;
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(vis[j]==false) ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}
/*
4 3
1 2 1 3
10 3
3 1 2 1 3 2 3 1 2 1
*/
