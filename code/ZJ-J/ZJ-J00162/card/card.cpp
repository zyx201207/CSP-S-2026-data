#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,m;
int a[200010];
vector<int>v(3010,0);

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	map<int,int>mp;
	stack<int>st;
	
	for(int i=1;i<=m;i++)mp[i]=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		while(!st.empty())st.pop();
		mp[a[i]]=1;
		for(int j=i+1;j<=n;j++){
			if(mp[a[j]]==0){
				st.push(a[j]);
				mp[a[j]]=1;
			}
			else{
				while(!st.empty()&&st.top()!=a[j]){
					mp[st.top()]=0;
					st.pop();
				}
			}
		}
		for(auto x:mp){
			if(x.second)v[x.first]++;
		}
		for(int j=1;j<=m;j++)mp[j]=0;
	}
	for(int i=1;i<=m;i++)cout<<v[i]<<' ';
}
/*
4 3
1 2 1 3
*/
