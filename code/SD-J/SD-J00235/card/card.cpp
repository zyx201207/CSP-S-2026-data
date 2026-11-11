#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m;
int a[N],b[N];
int vis[N];
stack<int> st;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			vis[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(vis[a[j]]!=0){
				while(st.top()!=a[j]){
					vis[st.top()]=0;
					st.pop();
				}
			} else{
				st.push(a[j]);
				vis[a[j]]=1;
			}
		}
		while(!st.empty()){
			b[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
