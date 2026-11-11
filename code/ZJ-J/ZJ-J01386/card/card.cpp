#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=5005;
int a[N];
int ans[N-2000];
bool flag[N];
stack<int> b;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(flag[a[j]]==1){
				while(b.top()!=a[j]) flag[b.top()]=0,b.pop();
				flag[b.top()]=0,b.pop();
			}
			b.push(a[j]);
			flag[a[j]]=1;
		}
		while(b.empty()==false){
			ans[b.top()]++;
			flag[b.top()]=0;
			b.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
}
