#include<iostream>
using namespace std;
int n,m,num[500005],cnt[500005],ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>num[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			if(cnt[num[j]] != 0){
				for(int k = cnt[j];k < j;k++){
					cnt[num[k]] = 0;
				}
			}
			cnt[num[j]] = j;
		}
		for(int j = 1;j <= m;j++){
			if(cnt[j]){
				ans[j]++;
			}
			cnt[j] = 0;
		}
	}
	for(int i = 1;i <= m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;//100+56+25+24=205 
}



















































































//
