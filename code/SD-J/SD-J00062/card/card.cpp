#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],vis[300005],cnt[300005];
string s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){//第i局 
		for(int j=i;j<=n;j++){//第j张 
			if(vis[a[j]]){
				int mid;
				for(int x=0;x<s.size();x++){
					if(s[x]-'0'==a[j]){
						mid=x;
					}
				}
				for(int x=mid+1;x<s.size();x++){
					vis[s[x]-'0']=0;
				}
				s.erase(mid+1);
			}else{
				s+=char(a[j]+'0');
				vis[a[j]]=1;
			}
		}
		for(int i=1;i<=m;i++){
			cnt[i]+=vis[i];
		}
		memset(vis,0,sizeof(vis));
	}
	for(int i=1;i<=m;i++){
		printf("%d ",cnt[i]);
	}
	return 0;
} 
