#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int n,m,a[500005],cnt[300005],vis[500005];
vector<int>num[500005];
int q[500005],len;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		num[a[i]].push_back(i);
	}for(int i=1;i<=n;i++){
		memset(vis,-1,sizeof vis);
		len=0;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]!=-1&&vis[a[j]]<=len){
				len=vis[a[j]]-1;
			}q[++len]=a[j];
			vis[a[j]]=len;
		}for(int j=1;j<=m;j++){
			for(int k=1;k<=len;k++){
				if(q[k]==j){
					cnt[j]++;break;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",cnt[i]);
	}printf("\n");
	return 0;
}
