#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Node{
	int vis,id;
};
int a[500005],q[500005],ans[300005];
Node vis[500005];
int head = 1,tail = 1;
void push(int x){
	q[tail++] = x;
} 
void pop(){
	head--;
} 
bool empty(){
	return head == tail;
} 
int size(){
	return head - tail;
} 
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		memset(q,0,sizeof(q));
		memset(vis,0,sizeof(vis));
		head = 1;
		tail = 1;
		for(int j = i;j <= n;j++){
			if(vis[a[j]].vis == 0){
				push(a[j]);
				vis[a[j]].vis = 1;
				vis[a[j]].id = tail - 1;
			}else{
				for(int k = head + 1;k <= tail;k++){
					vis[q[k]].vis = 0;
				}
				tail = vis[a[j]].id;
				push(a[j]);
				vis[a[j]].id = tail - 1;
			}
		} 
		for(int k = head;k < tail;k++){
			ans[q[k]]++;
//			cout << q[k] << ' ';
		} 
//		cout << endl;
	}
	for(int i = 1;i <= m;i++){
		cout << ans[i] << ' '; 
	}
	return 0;
}

