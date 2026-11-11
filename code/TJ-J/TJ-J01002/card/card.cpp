#include<bits/stdc++.h>
using namespace std;
int n,m,q[514514],cnt[514524];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>q[i];	
	}
	for(int i=1;i<=n;i++){
		set<int> st;
		for(int j=i;j<=n;j++){
			if(st.count(q[j])){
				st.clear();
			}st.insert(q[j]);
		}
		for(int j=1;j<=m;j++){
			if(st.count(j)){
				cnt[j]++;
			}
		}
	}for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
	return 0;
} 
