#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[500000+10];
int z[500000+10];//桌面 
int box[500000+10];//有没有这张牌
int id[500000+10];//第i张牌的位置
int box2[500000+10];//统计 
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){//第i轮游戏
		
		
		int cur=0;
		memset(z,0,sizeof(z));
		memset(box,0,sizeof(box));
		memset(id,0,sizeof(id));
		for(int j=i;j<=n;j++){//第j张卡片开始
			int x=a[j];
			
			if(box[x]==0){
				cur++;
				z[cur]=x;
				int ll;
				box[x]=1;
				
				id[x]=cur;
			}else{
				int y=id[x];
				for(int i=y+1;i<=n;i++){
					box[z[i]]=0;
					id[z[i]]=0;
				}			
				cur=y;
			}
			
		}
		for(int i=1;i<=cur;i++){
			int p=z[i];
			box2[p]++;
		
		
		}	
	}
	for(int i=1;i<=m;i++){
		cout<<box2[i]<<" ";
	}
	return 0;
}
