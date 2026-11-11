#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt,a[500005],chu[500005];
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		chu[i]==a[i];
		for(int j=i;j<=n;j++){
			if(chu[j]==a[i]){
				for(int k=j;k>0;k--){
					chu[k]=0;
					a[i]=0;	
				}
			}else{
				chu[j]=a[i];
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++) if(chu[j]==i) cnt+=1;
		cout<<cnt<<' ';
		cnt=0;
	}
	for(int k=1;k<=m;k++) chu[k]=0;
	return 0;
} 
/*
1.共有 n 张纸牌，从上到下的点数依次为 a 1 ,a 2 ,...,a n 。

2.每张牌的点数都是 1 到 m 之间的整数

3.进行 n 局相互独立的游戏

4.第 i (1 ≤ i ≤ n) 局中，他跳过前 i - 1 张牌，依次打出第i张到第n张牌，这
些牌的点数依次为 a i ,a i+1 ,...,a n 。

5.打出一张点数为 k 的牌时：若桌面上没有点数为 k 的牌，就将这张牌放在最右端；
否则，收走桌面上点数为 k 的牌及其右侧的所有牌，再把这张牌放在最右端。被收走
的牌在本局中不再使用。 

6.对于每个 i = 1,2,...,m，在所有 n 局游戏中，有多少局结束时桌面上留有点数为
 i 的牌。 
*/ 
