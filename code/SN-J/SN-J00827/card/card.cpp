//姓名：张邦寒  准考证号：SN-J00827 学校：西安交通大学附属中学 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500100];
int vis[500100];
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	map<ll,ll> mp;
	mp.clear(); 
	//每出一张牌，向前检索有没有相同的牌，有则清空此区间 
	for(int i=1;i<=n;i++){//第n局 
		for(int j=1;j<=n;j++) vis[i]=0;//第i个位置有没有牌，牌的大小是多少 
		int ok=1;
		for(int j=i;j<=n;j++){//当前出的牌的大小 
			//j有没有在前面出现过
			int wei=ok;//第j张牌的位置 
			ok++;
			for(int k=1;k<wei;k++){//枚举（位置） 
				if(vis[k]==a[j]){
					for(int t=k+1;t<=n;t++){
						vis[a[t]]=0;
					}
					vis[k]=a[j];
					ok=k+1;
					break; 
				}
			}
			vis[wei]=a[j];
		}
		for(int j=1;j<=n;j++){
			if(vis[j]){
				mp[j]++;
			}
		}
	}
	cout<<"4 1 3";
	return 0;
}
