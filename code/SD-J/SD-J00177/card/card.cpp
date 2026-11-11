#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m,a[N];
long long ans[M];
bool cnt[M];
void gx(int starti){
	stack<long long> st;
	for(int i=starti;i<=n;i++){
		if(cnt[a[i]]==0){
			cnt[a[i]]=1;
			st.push(a[i]);
		}else{
			while(cnt[a[i]]==1){
				cnt[st.top()]=0;
				st.pop();
			}
			st.push(a[i]);
			cnt[a[i]]=1;
		}
	}
	while(!st.empty()){
		ans[st.top()]++;
		cnt[st.top()]=0;
		st.pop();
	}
	return ;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		gx(i);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i];
		if(i!=m)cout<<" ";
	}
	return 0;
}

