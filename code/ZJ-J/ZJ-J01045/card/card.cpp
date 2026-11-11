#include <bits/stdc++.h>
using namespace std;
long long ans[5005]={};
long long a[5005]={};
long long n,m;
void game(long long idx){
	long long vis[5005]={},pos[5005]={},games[5005]={},len=1;
	for(int j=1;j<=m;j++){
		vis[j]=0,pos[j]=0,games[j]=0;
	}
	long long i=idx-1;
	while(i<=n){
		i++;
		if(vis[a[i]]==1){
			len-=i-games[a[i]];
			for(int j=games[a[i]];j<=i;j++){
				vis[pos[j]]=0,games[pos[j]]=0,pos[j]=0;
			}
		}pos[len]=a[i]; 
		vis[a[i]]=1;
		games[a[i]]=len;
		len++;
	}for(int i=1;i<=m;i++){
		ans[i]+=vis[i];
	}
}
int main(){	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	for(int i=1;i<=n;i++){
		game(i);
	}for(int i=1;i<=m;i++)cout << ans[i] << " ";
	return 0;
}
