#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans[300005];
bool flag[300005];
stack<int> q;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			while (flag[a[j]]){
				if (q.top()==a[j])
					flag[a[j]]=false;
				q.pop();
			}
			q.push(a[j]);
			flag[a[j]]=true;
		}
		while (!q.empty()){
			ans[q.top()]++;
			q.pop();
		}
	}
	for (int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
