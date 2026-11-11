#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
set<int> num;
stack<int> cards;
int ans[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	int q=0;
	while (q<n){
		q++;
		while (!cards.empty()) cards.pop();
		num.clear();
		for (int i=q;i<=n;i++){
			if (num.count(a[i])==0){
				cards.push(a[i]);
				num.insert(a[i]);
			}
			else{
				while (cards.top()!=a[i]){
					num.erase(cards.top());
					cards.pop();
				}
				cards.push(a[i]);
				num.insert(a[i]);
			}
		}
		for (int i=1;i<=m;i++){
			if (num.count(i)==1){
				ans[i]++;
			}
		}
	}
	for (int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
