#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],m,vis[300005],n,cnt[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int i=1;i<=n;i++){
		int now=0;
		memset(vis,0,sizeof(vis)); 
		for(int j=i;j<=n;j++){
			int pos=a[j];
			if(vis[pos]>=1){
				while(1){
					if(a[now]!=pos){
						vis[a[now]]--;
						now--;
					}
					else	break;
				}
			}
			else vis[pos]=1,now++;
		}
		for(int j=1;j<=m;j++){
			if(vis[j])	cnt[j]++;
		}
	}
	for(int i=1;i<=m;i++)	cout<<cnt[i]<<" ";
}
