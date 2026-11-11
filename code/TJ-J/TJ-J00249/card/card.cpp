#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int a[N],cnt[M],mp[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	stack<int> st;
	for(int i=1;i<=n;i++){
		int dtt=0;
		for(int j=i;j<=n;j++){
			if(mp[a[j]]==0){
				mp[a[j]]=j;
				st.push(a[j]);
			}else{
				for(int k=1;k<j-mp[a[j]]-dtt;k++){mp[st.top()]=0;st.pop();}
				dtt+=j-mp[a[j]];
				mp[a[j]]=j-dtt;
			}
		}
		while(!st.empty()){
			mp[st.top()]=0;
			cnt[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
} 
