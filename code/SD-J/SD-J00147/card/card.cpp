#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5*1e5+10,M=3*1e5+10;
int n,m;
int a[N];
int cnt[M];
bool vis[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		int f=false;
		memset(vis,sizeof vis,false);
		memset(cnt,sizeof cnt,0);
		for(int j=i;j<=n;j++){
			for(int k=i;k<=j;k++){
				if(f){
					vis[k]=true;
				}
				if(a[k]==a[j]){
					f=true;
					vis[k]=true; 
				}
			}
		}for(int j=i;j<=n;j++){
			if(!vis[i]){
				cnt[a[i]]++;
			}
		}for(int j=1;j<=m;j++){
			if(cnt[j]!=0)cout<<cnt[j]<<'\n';
		}
	}
	return 0;
}

