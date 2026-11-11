#include<bits/stdc++.h>
using namespace std;
int n , m;
int a[500001];
queue<int> que;
int main(){
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	stable_sort(a + 1, a + 1 + n);
	for(int i = 1;i <= n;i++) que.push(a[i]);
	for(int i = 1;i <= m;i++){
		cout << que.front();
		que.pop();
	}
	return 0;
}
