#include <bits/stdc++.h>
using namespace std;
const int N=1e5*5+5;
int n,m;
bool used[N];
int ans[N],a[N];
void gaming(int x){
	for(int i=1;i<=n;i++) used[i]=false;
	stack<int> st;
	for(int i=x;i<=n;i++){
		if(!used[a[i]]){
			used[a[i]]=true;
			st.push(a[i]);
		}
		else{
			while(st.top()!=a[i]){
				int x=st.top();
				used[x]=false;
				st.pop();
			}
		}
	}
	for(int i=1;i<=m;i++) if(used[i]) ans[i]++;
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) gaming(i);
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}