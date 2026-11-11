#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N],pre[N],cnt[M],c[N],l[M],r[M],isup;
int vis[N];
stack<int> st;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		while(!st.empty()){
			st.pop();
		}
		for(int j=1;j<=m;j++){
			vis[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				while(!st.empty()){
					if(st.top()==a[j]){
						vis[a[j]]--;
						st.pop();
						break;
					}
					vis[st.top()]--;
					st.pop();
				}
			}
			st.push(a[j]);
			vis[a[j]]++;
		}
		while(!st.empty()){
			cnt[st.top()]++;
			st.pop(); 
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}

