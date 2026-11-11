#include <bits/stdc++.h>
using namespace std;
int tong[500005],a[500005],ans[500005];
stack<int> q;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int tmp=1; tmp<=n; tmp++) { //摸牌的起始位置
		memset(tong,0,sizeof tong);//给桶置0
		for(int i=tmp; i<=n; i++) { //模拟放牌
			if(tong[a[i]]!=0) { //之前的都删了，放上我
				while(q.top()!=a[i]) {
					tong[q.top()]=0;
					q.pop();
				}
				tong[a[i]]=1;
				q.pop();//之前的全都删去了
				q.push(a[i]);
			} else {
				tong[a[i]]=1;
				q.push(a[i]);
			}
		}
		while(!q.empty())
		{
			ans[q.top()]++;
			q.pop();
		}
	}
	for(int i=1; i<=m; i++) {
		cout <<ans[i]<<" ";
	}
	return 0;
}

//优化的方法：模拟一局放牌，把所有其他还在栈中的数ans++就可以了

