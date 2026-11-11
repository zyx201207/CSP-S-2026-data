#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int ans[300005] = {0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	int r = 0;
	int start = 1;
	while(start <= n){
		r = start;
		bool vis[300005] = {0};
		while(r <= n){//一次游戏 
			if(vis[a[r]]){
				for(int j = r-1;j >= 1;j--){
					if(a[j] == a[r])break;
					else{
						vis[a[j]] = 0;
					}
				}
			}
			else{
				vis[a[r]] = 1;
			}
			r++;
		}//结束 
		for(int i = 1;i <= m;i++){
			if(vis[i]){
				ans[i]++;
			}
		}
		
		start++;
	}
	for(int i = 1;i <= m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
