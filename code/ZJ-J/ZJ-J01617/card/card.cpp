#include<bits/stdc++.h>
#define pb push_back

using namespace std;

const int N=5e5+5;
int n,m,a[N],ans[N];
bool vis[N];
stack<int> st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int x=a[j];
			if(!vis[x]){
				vis[x]=1;
				st.push(x);
			}else{
				while(!st.empty()&&st.top()!=x){
					vis[st.top()]=0;st.pop();
				}
			}
		}
		while(!st.empty()){
			int x=st.top();st.pop();
			vis[x]=0;ans[x]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	cout<<"\n";
}