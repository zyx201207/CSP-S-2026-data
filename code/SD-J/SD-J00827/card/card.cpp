#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int lst[500005];
int ans[500005];
int vis[500005];
int lowbit(int x){return x&(-x);}
void add(int x,int y){
	for(int i = x;i <= n;i += lowbit(i)) vis[i] += y;
}
int ask(int x){
	int sum = 0;
	for(int i = x;i;i -= lowbit(i)) sum += vis[i];
	return sum;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	int cnt = 0;
	bool flag = 1;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		flag &= (a[i] >= a[i-1]);
		cnt += (a[i] != a[i-1]);
	}
	if(n <= 5000){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++) lst[j] = 0;
			for(int j = 1;j <= n;j++) vis[j] = 0;
			for(int j = i;j <= n;j++){
				if(!lst[a[j]]||vis[lst[a[j]]]) lst[a[j]] = j;
				else{
					for(int k = lst[a[j]];k < j;k++) vis[k] = 1;
					lst[a[j]] = j;
				}
			}
			for(int j = i;j <= n;j++){
				if(!vis[j]) ans[a[j]]++;
			}
//			for(int j = 1;j <= m;j++) cout << ans[j] << " ";
//			cout << "\n";
		}
		for(int i = 1;i <= m;i++) cout << ans[i] << " ";
	}else if(flag){
		for(int i = 1;i < n;i++){
			if(a[i] != a[i+1]) ans[a[i]] = i;
		}
		ans[a[n]] = n;
		for(int i = 1;i <= m;i++) cout << ans[i] << " ";
	}else{
		cout << "csp-j2026";
	}
}
