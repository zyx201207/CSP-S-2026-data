#include<bits/stdc++.h> 
using namespace std;
int cnt[100005];
int pai[100005];
int zhuo[100005];
//4 3 1 2 1 3
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>pai[i];
	}
	int cntu=0;
	int jilu=0;
	for(int a=0;a<=n;a++){//局数 
		for(int i=jilu;i<n;i++){//从上局结束的排数开始 
			if(zhuo[i]==0){//如果没牌就放牌
				zhuo[i]=pai[i]; //放牌 
				cnt[pai[i]]++;//记录牌的出现 
				for(int j=0;j<i;j++){
					for(int z=0;z<i;z++){
						if(zhuo[j]==zhuo[z]){//检测是否有相同牌 
							cout<<1;
							for(int z=j+1;z<=i;z++){//清空右边 
								zhuo[z]==0;
							}
						}
					}
				}
				jilu=i;
				break;
			}       
			   
		}
	}
	for(int z=0;z<=m;z++){
		cout<<cnt[z]<<" "; 
	}
//	for(int z=0;z<n;z++){
//		cout<<cnt[pai[z]]<<" "; 
//	}
	return 0;
}
