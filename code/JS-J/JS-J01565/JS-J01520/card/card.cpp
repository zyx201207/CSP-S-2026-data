#include<bits/stdc++.h>
using namespace std;
bool ontable[300005];
int cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	stack<int> st;
	for(int l=n-1;l>=0;l--){
		for(int i=l;i<n;i++){
			if(!ontable[a[i]]){
				st.push(a[i]);
				ontable[a[i]]=1;
				continue;
			}
			while(st.top()!=a[i]){
				ontable[st.top()]=0;
				st.pop();
			}
		}
		while(!st.empty()){
			cnt[st.top()]++;
			ontable[st.top()]=0;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
	return 0;
}
