#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],num[300005];
bool vis[300005];
stack<int> st;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			vis[j]=false;
		}
		for (int j=i;j<=n;j++){
			st.push(a[j]);
			if (vis[a[j]]){
				st.pop();
				while (!st.empty()&&st.top()!=a[j]){
					st.pop();
				}
			}else{
				vis[a[j]]=true;
			}
		}
		while (!st.empty()){
			num[st.top()]++;
			st.pop();
		}
	}
	for (int i=1;i<=m;i++){
		cout<<num[i];
		if (i!=m)cout<<" ";
	}
	cout<<endl;
	return 0;
}
