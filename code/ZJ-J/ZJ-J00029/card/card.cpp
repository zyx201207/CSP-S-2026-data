#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],inst[200005],cnt[200005],pos[200005],ans[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(1ll*n*n>=1e9){
		for(int i=1;i<=n;i++){
			if(!cnt[a[i]]){
				pos[a[i]]=i;
			}
			cnt[a[i]]++;
		}
		for(int i=1;i<=m;i++){
			cout<<pos[i]+cnt[i]-1;
		}
	}
	else{
		stack<int> st;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(!inst[a[j]]){
					inst[a[j]]=1;
					st.push(a[j]);
				}
				else{
					while(st.top()!=a[j]){
						inst[st.top()]=0;
						st.pop();
					}
				}
			}
			while(!st.empty()){
				ans[st.top()]++;
				inst[st.top()]=0;
				st.pop();
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
	}
	return 0;
}