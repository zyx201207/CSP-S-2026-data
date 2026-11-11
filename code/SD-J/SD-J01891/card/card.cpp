#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+5;
const int M=3e5+5;
int n,m,v[M],a[N],t[M],ans[M];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans[a[i]]+=i;
	}
	stack<int>st;
	for(int i=0;i<n;i++){
		memset(v,0,sizeof(v));
		for(int j=i+1;j<=n;j++){
			if(v[a[j]]){
				ans[a[j]]--;
				while(st.top()!=a[j]){
					ans[st.top()]--;
					v[st.top()]=0;
					st.pop();
					
				}
			}else{
				st.push(a[j]);
				v[a[j]]=1;
			}
		}
		while(!st.empty())st.pop();
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
