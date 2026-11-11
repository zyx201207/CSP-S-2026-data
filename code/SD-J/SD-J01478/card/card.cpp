#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=2e5+5;
int maxx=-inf;
int m,n,ans=0;
struct node{
	int id,d;
}a[N];
vector<node> z;
bool vis[N]={0};
int cnt[N]={0};
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].d;
		a[i].id=i;
	}
	for(int i=1;i<=n;i++){
		int w=1;
		int end=i;
		while(end){
			if(vis[w]){
				w++;
			}else{
				end--;
			}
		}
		vis[w]=1;
		int ok=0;
		if(!z.empty()){
			for(int j=0;j<z.size();j++){
				if(z[i].d==a[w].d){
					ok=1;
					break;
				}
			}
		}
		if(ok){
			vector<node> z;
		}
		z.push_back(a[w]);
		cnt[a[w].d]++; 
	}
	for(int i=0;i<=m;i++){
		if(cnt[i]){
			cout<<cnt[i]<<' ';
		}
	}
	return 0;
}
