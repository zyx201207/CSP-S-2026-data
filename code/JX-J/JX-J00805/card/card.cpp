#include <bits/stdc++.h>
using namespace std;
int n,m;
deque<int> st;
int ans[300010];
int a[500010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		bool in_stack[500010]={};
		for(int j=i;j<=n;j++){
			if(in_stack[a[j]]){
				while(!st.empty()&&st.front()!=a[j]){
					in_stack[st.front()]=0;
					ans[st.front()]--;
					st.pop_front();
				}
			}else{
				st.push_front(a[j]);
				in_stack[st.front()]=1;
				ans[a[j]]++;
			}
		}
//		for(int k:st){
//			cout<<k<<" ";
//		}
//		cout<<"\n";
		while(!st.empty()){
			st.pop_front();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
