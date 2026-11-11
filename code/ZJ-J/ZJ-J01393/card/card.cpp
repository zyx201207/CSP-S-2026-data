#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+5;
int n,m,a[maxn],b[maxn],cnt[maxn],vis[maxn],ans[maxn];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			vis[j]=0;
			cnt[j]=0;
		}
		stack<int>st;
		for(int j=i;j<=n;j++){
			if(cnt[a[j]]){
				while(st.top()!=a[j]){
					cnt[st.top()]--;
					st.pop();
				}
			}
			else{
				st.push(a[j]);
				cnt[a[j]]++;
			}
		}
		while(!st.empty()){
			vis[st.top()]=1;
			st.pop();
		}
		for(int j=1;j<=m;j++){
			ans[j]+=vis[j];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

