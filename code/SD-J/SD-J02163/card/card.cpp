#include<bits/stdc++.h>	//1-12(12) 4*12=48
#define ll long long
using namespace std;
ll n,m,a[500005],ans[300005],t[300005];
stack<ll> st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(t[a[j]]){
				while(!st.empty()&&st.top()!=a[j]){
					t[st.top()]=0;
					st.pop();
				}
			}else{
				st.push(a[j]);
				t[a[j]]=1;
			}
		}
		while(!st.empty()){
			ans[st.top()]++;
			t[st.top()]=0;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
