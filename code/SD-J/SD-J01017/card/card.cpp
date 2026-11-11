#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[500005];
int t[300005];
int b[500005]={0};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		bool vis[500005]={0};
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0){
				t[a[j]]++;
				vis[a[j]]=1;
				b[a[j]]=j;
			}else{
				vis[a[j]]=1;
				for(int k=b[a[j]]+1;k<j;k++){
					if(vis[a[k]]==1){
						t[a[k]]--;
					}
					vis[a[k]]=0;
				}
			}
		}
	} 
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
} 
