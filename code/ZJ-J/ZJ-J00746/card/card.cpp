#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
int a[1000005],b[100005];
int cnt[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		bool vis[100005],wz[100005];
		for(int i=1;i<=n;i++){
			b[i]=a[i];
		}
		for(int j=i;j<=n;j++){
			if(!vis[b[j]]){
				vis[b[j]]=1;
				wz[b[j]]=j;
			}
			else{
				for(int k=wz[b[j]]+1;k<j;k++){
					b[k]=0;
					vis[b[k]]=0;
				}
				vis[b[j]]=1;
				wz[b[j]]=j;
			}
		}
		for(int k=1;k<=m;k++){
			if(vis[k]){
				cnt[k]++;
			}
		}
	}
	for(int k=1;k<=m;k++){
		cout<<cnt[k]<<" ";
	}
	return 0;
}