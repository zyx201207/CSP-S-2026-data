#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int a[N];
bool vis[N],tag[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int i=30;i>=0;i--){
		memset(tag,0,sizeof tag);
		int sum=0,y=1<<i;
		for(int j=1;j<=n;j++){
			if(!vis[j] && (a[j]&y))	sum++;
			else tag[j]=1;
		}
		if(sum>=m){
			ans+=y;
			for(int j=1;j<=n;j++)	vis[j]|=tag[j];
		}
	}
	cout<<ans<<'\n';
	return 0;
}
