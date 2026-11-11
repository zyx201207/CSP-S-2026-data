#include<bits/stdc++.h>
using namespace std;
stack<int> st;

int a[200004];
bool use[200004];
int ans[200004];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	
	for(int i=1;i<=n;i++){
		memset(use,false,sizeof(use));
		for(int now=i;now<=n;now++){
			if(use[a[now]]){
				while(st.top()!=a[now]){
					use[st.top()]=!use[st.top()];
					st.pop();
				}
			}else{
				st.push(a[now]);use[a[now]]=true;
			}
		}
		while(!st.empty()){
			ans[st.top()]++;st.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}

