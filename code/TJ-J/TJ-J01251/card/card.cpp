#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int tong[500005];
int cnt[500005];
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
//输入
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]); 
		tong[a[i]]++;
	}
//出牌 
	for(int i=1;i<=n;i++){
		for(int q=n;q>=1;q--){
			if(tong[a[q]]>1){
			//清空牌堆 
			for(int j=q-1;j>=0;j--){
				if(a[j]==a[q]){
					break;
				}
				a[j]==0;
			}
			}	
			//继续
		
		}
		//记录剩余的牌数 
		for(int j=1;j<=n;j++){
			if(a[j]>0)
			cnt[j]==a[j];
		}
}
	for(int i=1;i<=m;i++){
		printf("%d ",cnt[i]);
	}
	return 0;
} 
