#include<bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define ft first
#define sd second
using namespace std;
int n,m;
int val[500010];
bool te=1;
bool inst[300010];
int ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>val[i];
		if(val[i]<val[i-1]){
			te=0;
		}
	}
	if(te){
		for(int i=1;i<=n;i++){
			if(i==n||val[i]!=val[i+1]){
				cout<<i<<' ';
			}
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(inst,0,sizeof(inst));
		stack<int> st;
		for(int j=i;j<=n;j++){
			if(!inst[val[j]]){
				st.push(val[j]);
				inst[val[j]]=1;
			}
			else{
				while(st.top()!=val[j]){
					inst[st.top()]=0;
					st.pop();
				}
			}
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
