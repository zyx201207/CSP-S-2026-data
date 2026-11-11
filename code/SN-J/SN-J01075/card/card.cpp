#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5, M=3e5+5; 
int n,arr[N],m, tab[M],cnt, pos[M], ans[M];
		//当前桌面卡牌情况 桌面卡牌数量  上一个i号卡牌出现的位置 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	for(int k=1;k<=n;k++){
		cnt=0;
		memset(tab,0,sizeof(tab));
		memset(pos,0,sizeof(pos));
		for(int i=k;i<=n;i++){
			if(pos[arr[i]]==0){
				tab[++cnt] = arr[i];
				pos[arr[i]] = cnt;
			}
			else
				for(;cnt>pos[arr[i]];cnt--)
					pos[tab[cnt]] = 0;
		}
		for(int i=1;i<=cnt;i++)
			ans[tab[i]]++;
	}
	for(int i=1;i<=m;i++)
		printf("%d ",ans[i]);
	printf("\n");
	
	return 0;
} 
