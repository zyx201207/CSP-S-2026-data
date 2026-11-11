#include<bits/stdc++.h>
using namespace std;
/*====================*/
using lnt=long long;
/*====================*/
int cnt[300500];
int arr[500500];
int ans[300500];
stack<int> st;
int n,m;
/*====================*/
void F___________1(){
	for(int i=n;i>=1;i--){
		if(cnt[arr[i]]){
			while(st.top()!=arr[i]) cnt[st.top()]--,ans[st.top()]-=i,st.pop();
		}
		else{
			st.push(arr[i]);
			cnt[arr[i]]++;
			ans[arr[i]]+=i;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	cout<<'\n';
}
/*====================*/
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	if(1ll*n*n>600000000ll){
		F___________1();
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(cnt[arr[j]]){
				while(st.top()!=arr[j]) cnt[st.top()]--,st.pop();
			}
			else{
				st.push(arr[j]);
				cnt[arr[j]]++;
			}
		}
		while(!st.empty()){
			ans[st.top()]++;
			cnt[st.top()]--;
			st.pop();
		}
	}
	for(int j=1;j<=m;j++) cout<<ans[j]<<" ";
	cout<<'\n';
	return;
}
/*====================*/
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int T=1; //cin>>T;
	while(T--) Solve();
	return 0;
}
