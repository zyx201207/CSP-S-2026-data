#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
stack<int> st;
int x[N];
int ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int qqq=1;qqq<=n;qqq++){
		memset(x,0,sizeof(x));
		for (int i=qqq;i<=n;i++){
			if (x[a[i]]){
				int fr=st.top();
				while(fr != a[i]){
					fr=st.top();
					x[fr]--;
					st.pop();
				}
				st.push(a[i]);
			}
			else{
				st.push(a[i]);
				x[a[i]]++;
			}
		}
		while(!st.empty()){
			ans[st.top()]++;
			st.pop();
		}
	}
	for (int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
