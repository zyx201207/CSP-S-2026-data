#include<bits/stdc++.h>
using namespace std;

stack<int> st;

int n,m,a[5001],ans[3001];

bool used[3001];

void solve(int k){
	for(int i=1;i<=m;i++) used[i]=0;
	for(int i=k;i<=n;i++){
		if(!used[a[i]]){
			used[a[i]]=1;
			st.push(a[i]);
		}
		else{
			while(st.top()!=a[i]){
				used[st.top()]=0;
				st.pop();
			}
		}
	}
	for(int i=1;i<=m;i++) ans[i]+=used[i];
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) solve(i);
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
}
