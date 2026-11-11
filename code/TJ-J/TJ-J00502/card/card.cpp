#include<bits/stdc++.h>
using namespace std;
int a[500010];
int cnt[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	stack<int> q;
	//1 2 2 2 3
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++){//第i局 
		for(int j = 1;j <= n;j++) q.push(a[j]);//初始化栈 
		for(int j = i;j <= n;j++){//从j开始放牌 
			if(q.top() == a[j]) q.pop();
			else q.push(a[j]);
		}
		stack<int> q1; 
		for(int j = 1;j <= m;j++){
			if(j%2){
				if(q.top() != j){
					q1.push(q.top());
					q.pop();
				}else{
					cnt[j]++;
				}
			}else{
				if(q1.top() != j){
					q.push(q1.top());
					q1.pop();
				}else{
					cnt[j]++;
				}
			}
		}
	}
	for(int i = 1;i <= m;i++) cout << cnt[i] << ' '; 
	return 0;
}
