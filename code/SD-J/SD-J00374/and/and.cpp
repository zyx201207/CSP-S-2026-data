#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+7;
int n,m,a[N];
ll ans=0;
bool vis[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	memset(vis,1,sizeof(vis));
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int id=30;id>=0;id--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(vis[i]&&(a[i]&(1<<id))){
				cnt++;
			}
		}
		if(cnt>=m){
			ans|=(1<<id);
			for(int i=1;i<=n;i++){
				if(!vis[i])continue;
				if(!(a[i]&(1<<id)))vis[i]=0;
			}
		}
//		for(int i=1;i<=5;i++)cout<<vis[i]<<" ";
//		cout<<"\n";
	}
	cout<<ans<<"\n";
	return 0;
}
/*
5 3
31 3 1 15 7
1
11
111
1111
11111
*/
