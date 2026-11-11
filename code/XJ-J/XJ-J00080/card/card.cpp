#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int n,m;
int a[N],b[N],l,t[N],vis[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=1;k<=l;k++){
				if(b[k]==a[j]){
					l=k-1;
					break;
				}
			}
			b[++l]=a[j];
		}
		for(int j=1;j<=l;j++){
			if(vis[b[j]]==0){
				vis[b[j]]=1;
				t[b[j]]++;
			}
		}
		l=0;
		memset(vis,0,sizeof(vis));
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<' ';
	}
	return 0;
}

