#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int nw[500005];
int cnt[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	stack<int>st;
	for(int j=n;j>=1;j--){
		if(nw[a[j]]==1){
			while(st.top()!=a[j]){
				nw[st.top()]=0;
				st.pop();
			}
		}
		else{
			st.push(a[j]);
			nw[a[j]]=1;
		}
		for(int k=1;k<=m;k++){
			if(nw[k]==1) cnt[k]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
}