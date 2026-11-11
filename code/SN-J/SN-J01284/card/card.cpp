#include<bits/stdc++.h>
using namespace std;
int a[500001];
int ans[500001];
stack<int> st;
bool in[500001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(in,0,sizeof(in));
		while(!st.empty()) st.pop();
		for(int j=i;j<=n;j++){
			if(!in[a[j]]) in[a[j]]=1,st.push(a[j]),ans[a[j]]++;
			else{
				while(!st.empty()&&st.top()!=a[j]) ans[st.top()]--,in[st.top()]=0,st.pop();
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
