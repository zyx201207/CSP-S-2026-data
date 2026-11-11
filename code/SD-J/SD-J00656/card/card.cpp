#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+10;
int n,m;
int a[maxn],ans[maxn];
bool b[maxn];
stack<int> q;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			b[j]=false;
		}
		for(int j=i;j<=n;j++){
			if(b[a[j]]){
				while(true){
					if(q.empty())break;
					int k=q.top();
					if(k!=a[j])q.pop();
					else break;
				}
			}
			else{
				q.push(a[j]);
				b[a[j]]=true;
			}
		}
		while(!q.empty()){
			ans[q.top()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
} 
