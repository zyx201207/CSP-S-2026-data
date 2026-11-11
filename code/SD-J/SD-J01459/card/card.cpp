#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int a[210000],vis[210000],ans[210000],lst[210000];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,fl=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])fl=0;
	}
	if(fl){
		for(int i=n;i>=1;i--){
			if(!lst[a[i]])lst[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			cout<<lst[i]<<' ';
		}
		return 0;
	}
	stack<int>st;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			vis[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				while(!st.empty()&&st.top()!=a[j]){
					vis[st.top()]=0;
					st.pop();
				}
//				cout<<st.size()<<"!!!!!"<<endl;
				st.pop();
			}
			st.push(a[j]);
			vis[a[j]]=1;
		}
		while(!st.empty()){
			ans[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
} 
