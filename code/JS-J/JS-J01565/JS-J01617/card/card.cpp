#include<bits/stdc++.h>
using namespace std;
int a[500005],mp[300005];
unordered_set<int> st,st2;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		st.clear();
		st2.clear();
		for(int j=i;j<=n;j++){
			if(st.find(a[j])!=st.end()){
				for(int x:st){
					if(x!=a[j]) st2.insert(x);
					else break;
				}
				st.clear();
				st=st2;
				st2.clear();
			}
			st.insert(a[j]);
		}
		for(auto x:st) mp[x]++;
	}
	for(int i=1;i<=m;i++){
		cout<<mp[i]<<" ";
	}
	return 0;
}
