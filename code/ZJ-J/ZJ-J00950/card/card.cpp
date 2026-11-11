#include<bits/stdc++.h>
using namespace std;
/*
RP++RP++RP++RP++RP++
RP++RP++RP++RP++RP++
RP++RP++RP++RP++RP++
RP++RP++RP++RP++RP++
RP++RP++RP++RP++RP++
*/
const int N=2e5+5;
int dis[300005],a[N],n,m;
map<int,bool>v;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		v.clear();
		for(int j=i;j<=n;j++){
			if(!v[a[j]]){
				v[a[j]]=1;
			}
			else {
				for(int k=j-1;a[k]!=a[j];k--){
					v[a[k]]=0;
				}
			}
		}
		for(auto it:v){
			if(it.second){
				dis[it.first]++;
			}
		}
	}for(int i=1;i<=m;i++)cout<<dis[i]<<" ";
	return 0;
}
