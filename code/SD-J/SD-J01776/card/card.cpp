#include<bits/stdc++.h>
#define ll long long
#define mes(a,b) memset(a,b,sizeof a);
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
stack<int> st,st2;
int mp[N];
int ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		mes(mp,0);
		for(int i=k;i<=n;i++){
			if(mp[a[i]]==0){
				st.push(a[i]);
				mp[a[i]]++;
			}else{
				while(!st.empty()&&st.top()!=a[i]){
					if(mp[st.top()]==1) mp[st.top()]=0;
					st.pop();
				}
			}
		}
		while(!st.empty()){
			ans[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}

