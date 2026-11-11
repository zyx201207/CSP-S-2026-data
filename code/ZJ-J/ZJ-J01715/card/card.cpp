#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m;
int a[N],ans[M];
bool bj[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		stack<int> st;
		memset(bj,0,sizeof(bj));
		for(int j=i;j<=n;j++){
			if(bj[a[j]]){
				while(!st.empty() && st.top()!=a[j]){
					bj[st.top()]=0;
					st.pop();
				}
			}else{
				st.push(a[j]);
				bj[a[j]]=1;
			}
		}
		while(!st.empty()){
			int t=st.top();
			ans[t]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
