#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[200010];
set<int> se;
int numb[300010],ansb[300010],b[300010];
int v[300010],idx;
int vis[300010],cnt;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	int f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])f=1;
		b[a[i]]++;
	}
	int t=0;
	for(int i=1;i<=n;i++){
		if(b[a[i]]!=1){
			t=1;
		}
	}
	if(!t){
		for(int i=1;i<=n;i++){
			cout<<b[a[i]]<<" ";
		}
	}
	if(!f){
		for(int i=1;i<=n;i++){
			numb[a[i]]++;
			se.insert(a[i]);
		}
		for(int y:se){
			ansb[y]=n;
		}
		for(int i=2;i<=n;i++){
			numb[a[i-1]]--;
			if(numb[a[i-1]]==0){
				se.erase(a[i-1]);
				ansb[a[i-1]]-=(n-i+1);
			}
		}
		for(int i=1;i<=m;i++){
			cout<<(int)(ansb[i])<<" ";
		}
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=idx;j++){
				v[j]=0;vis[j]=0;
			}
			for(int j=1;j<=m;j++){
				numb[j]=0;
			}idx=0;
			for(int j=i;j<=n;j++){
				numb[a[j]]++;
				v[++idx]=a[j];
				if(numb[a[j]]>=2&&cnt>=2){
					for(int k=j-1;k>=1;k--){
						vis[k]=1;
						if(a[k]==a[j]){
							break;
						}
					}
					numb[a[j]]=0;
				}cnt=0;
				for(int j=1;j<=idx;j++){
					if(vis[j]==0){
						cnt++;
					}
				}
			}for(int j=1;j<=idx;j++){
				if(!vis[j]){
					ansb[v[j]]++;
				}
			}	
		}
		for(int i=1;i<=m;i++){
			cout<<ansb[i]<<" ";
		}
	}
	return 0;
}
