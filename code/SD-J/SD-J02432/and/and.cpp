#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[100000000100],i,j,c,ans;
	bool b[100000100];
	stack<int>st;
	cin>>n>>m;
	for(i=1;1<=n;i++){
		for(j=1;j<=m;j++){
			cin>>a[i];
			st.push(i);
		}
		st.pop();
		ans=max(a[c],a[c-1]);
	}
	
	cout<<ans;
}
