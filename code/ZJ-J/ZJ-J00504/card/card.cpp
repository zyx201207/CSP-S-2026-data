#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int a[maxn],l[maxn],r[maxn],cnt[maxn];
bool vis[maxn];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) vis[j]=0;
		for(int j=1;j<=m;j++) l[j]=n+1,r[j]=0;
		for(int j=i;j<=n;j++){
			l[a[j]]=min(l[a[j]],j);
			r[a[j]]=max(r[a[j]],j);
		}
		for(int j=1;j<=m;j++){
			for(int k=l[j];k<r[j];k++){
				vis[k]=1;
			}
		}
		for(int j=i;j<=n;j++){
			if(vis[j]==0) cnt[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}