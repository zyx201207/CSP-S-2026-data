#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[300010];
stack<long long> st;
bool count(stack<long long> st,long long x){
	while(!st.empty()){
		if(st.top()==x) return true;
		st.pop();
	}
	return false;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			while(count(st,a[j])) st.pop();
			st.push(a[j]);
		}
		while(!st.empty()){
			b[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<' ';
	return 0;
}
