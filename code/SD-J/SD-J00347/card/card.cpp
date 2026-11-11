#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
int a[MAXN],q[MAXN],n,m,ans = 0;
int fin(int x,int y){
	for(int i = y;i >= 1;i--){
		if(q[i] == x)return i;
	}
	return y;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		int top = 1;
		q[top] = a[i];
	}
	for(int j = 1;j <= m;j++){
		int p = fin(a[j],top);
		top = p;
		q[top] = a[j];
	}
	for(int j = 1;j <= m;j++){
		if(fin(j,top)!=top+1)ans[j]++;
	}
	for(int j = 1;j <= m;j++){
		cout << ans[j] << " ";
	}
	return 0;
}
