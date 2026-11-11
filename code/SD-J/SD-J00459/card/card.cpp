#include<bits/stdc++.h>
using namespace std;
int n,m,a[500002],ans[300002],b[300002];
stack<int>st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++){
			b[a[j]]++;
			if(b[a[j]]>=2){
				b[a[j]]--;
				while(!st.empty()){
					if(st.top()==a[j]){st.pop();break;}
					b[st.top()]--;
					st.pop();
				}
			}
			st.push(a[j]);
		}
		while(!st.empty()){
			ans[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
