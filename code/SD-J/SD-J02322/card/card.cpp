#include<bits/stdc++.h>//×£ÎÒ¿ªÖÇ£¬ÓÀ²»±©Áã 
using namespace std;
int a[200001],pos[200001],cnt[200001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i<=n;i++)cin >> a[i];
	for(int i = 1;i<=n;i++){
		memset(pos,-1,sizeof(pos));
		for(int j = i;j<=n;j++){
			if(pos[a[j]]!=-1){
				for(int k = pos[a[j]];k<=j;k++){
					pos[a[k]]=-1;
				}
			}
			pos[a[j]]=j;
		}
		for(int j = i;j<=n;j++){
			if(pos[a[j]]!=-1){
				cnt[a[j]]++;
				pos[a[j]]=-1;
			}
		}
	}
	for(int i = 1;i<=m;i++)cout <<cnt[i]<<" ";
	return 0;
} 
