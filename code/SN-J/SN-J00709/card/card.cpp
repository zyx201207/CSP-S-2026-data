//li wen lin
//xi an shi yuan dong di er zhong xue
//SN-J00709
#include<bits/stdc++.h>
using namespace std;
long long m,n;
long long a[50010],ans[50010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	string y="";//游戏牌串 
	for(int i=1;i<=n;i++){//i 局游戏 
		y="";//清零
		for(int j=i;j<=n;j++){//从i开始 
			y+=a[j];
			for(int k=y.size();k>=1;k--){
				
			}
		}
	}
	return 0;
	
}

