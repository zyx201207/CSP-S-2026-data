#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m;
int a[N];
int cnt[M];
bool vis[M];
stack<int> st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5000){
		for(int i=1;i<=n;i++){
			memset(vis,false,sizeof(vis));
			for(int j=i;j<=n;j++){
				if(!vis[a[j]]){
					vis[a[j]]=true;
					cnt[a[j]]++;
					st.push(a[j]);
				}
				else{
					while(!st.empty() && st.top()!=a[j]){
						vis[st.top()]=false;
						cnt[st.top()]--;
						st.pop();
					}
				}
			}
			while(!st.empty()){
				st.pop();
			}
		}
		for(int i=1;i<=m;i++){
			cout<<cnt[i]<<' ';
		}
		return 0;
	}
	else if(m<=2){
		if(m==1){
			cout<<n;
			return 0;
		}
		else{
			for(int i=1;i<=n;i++){
				cnt[a[i]]++;
				if(a[n]!=a[i]){
					cnt[a[n]]++;
				}
			}
			cout<<cnt[1]<<' '<<cnt[2];
			return 0;
		}
	}
	else if(n<=10000){
		for(int i=1;i<=n;i++){
			memset(vis,false,sizeof(vis));
			for(int j=i;j<=n;j++){
				if(!vis[a[j]]){
					vis[a[j]]=true;
					cnt[a[j]]++;
					st.push(a[j]);
				}
				else{
					while(!st.empty() && st.top()!=a[j]){
						vis[st.top()]=false;
						cnt[st.top()]--;
						st.pop();
					}
				}
			}
			while(!st.empty()){
				st.pop();
			}
		}
		for(int i=1;i<=m;i++){
			cout<<cnt[i]<<' ';
		}
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			cnt[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			cout<<cnt[i]<<' ';
		}
		return 0;
	}
	return 0;
} 
