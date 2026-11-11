#include<bits/stdc++.h>
using namespace std;
int n,m,a[500100],k[300100],t[300100];
stack<int> st;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(t[a[j]]){
				while(st.top()!=a[j]){
					t[st.top()]=0;
					st.pop();
				}
			}else t[a[j]]=1,st.push(a[j]);
		}
		for(int j=1;j<=m;j++) k[j]+=t[j],t[j]=0;
	}
	for(int i=1;i<=m;i++) cout<<k[i]<<' ';
	return 0;
}