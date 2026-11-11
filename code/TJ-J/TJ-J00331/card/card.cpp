#include<bits/stdc++.h>
using namespace std;
//读入顺序即deck(top->) 
int tc[300010],tcl=0;
int n,m,nc,i,j;
int hp[300010];
int ans[500010];
int deck[200000000];
int main(){
	freopen("card1.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	
	for(i = 1;i <= n;i++){
		cin >> deck[i];
	}
	for(int k = 1;k <= n;k++){
		for(i = k;i<=n;i++){
			nc = deck[i];
			if(hp[nc] == 0){
				hp[nc] = tcl;
				tc[tcl] = nc;
				tcl++;
			}else{
				for(j = tcl-hp[nc];j < tcl;j++){
					hp[tc[j]] = 0;
				}
				tcl = tcl-hp[nc];
				hp[nc]=tcl;
				tcl++;//+1 => 再把这张牌放在最右端
			}
		}
		for(i = 0;i<tcl;i++){
			ans[tc[i]]++;
			tc[i] = 0;
			for(int f = 1;f <= n;f++)hp[f] = 0;
			tcl = 0;
		}
	}
	for(i = 0;i<500010;i++){
		if(ans[i] > 0) cout << ans[i] << " ";
	}
	return 0;
}
