#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=510,M=310;
ll n,m,a[N],cnt[M],id[N];
stack<int> st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		while(!st.empty()) st.pop();
		for(int j=1;j<=n;j++){
			id[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(id[j]==0){
				st.push(a[j]);
				id[j]=st.size();
			}else{
				while(!st.empty()&&st.top()!=a[j]){
					st.pop();
				}
			}
		}
		while(!st.empty()){
			cnt[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
