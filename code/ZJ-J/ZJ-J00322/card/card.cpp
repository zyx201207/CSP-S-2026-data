#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=5e5+5;
const int MAXM=3e5+5;
int n,m,a[MAXN],vis[MAXM],cnt[MAXM];
stack<int> st;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++){
			st.push(a[i]);
			if(vis[a[i]]==1){
				st.pop();
				while(st.top()!=a[i]){
					vis[st.top()]=0;
					st.pop();
				}
			}
			vis[a[i]]=1;
		}
		for(int i=1;i<=m;i++){
			if(vis[i]==1){
				cnt[i]++;
				vis[i]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout << cnt[i] <<" ";
	}
	return 0;
}
