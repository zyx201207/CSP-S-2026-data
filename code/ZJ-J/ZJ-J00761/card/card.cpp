#include<bits/stdc++.h>
using namespace std;
constexpr int N = 5e5 + 10;
int a[N],n,pos[N],m,ans[N];
bool is[N],flag[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++){
		memset(pos,0,sizeof pos);
		memset(is,false,sizeof is);
		memset(flag,false,sizeof flag);
		for(int j = i;j <= n;j++){
			if(pos[a[j]]){
				for(int k = pos[a[j]];k < j;k++) is[k] = true;
				pos[a[j]] = j;
			}else pos[a[j]] = j;
		}
		for(int j = i;j <= n;j++){
			if(!is[j]) flag[j] = true;
		}
		for(int j = 1;j <= n;j++){
			if(flag[j]) ans[a[j]]++;
		}
	}
	for(int i = 1;i <= m;i++){
		cout << ans[i] << " ";
	}
	return 0;
}