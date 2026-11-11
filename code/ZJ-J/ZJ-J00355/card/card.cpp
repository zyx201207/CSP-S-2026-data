#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=5e5+5;
int n,m,a[MAXN],ans[MAXN];
bool vis[MAXN];
stack<int>s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0)vis[a[j]]=1;
			else{
				while(s.size()){
					if(s.top()==a[j]){
						s.pop();
						break;
					}
					s.pop();
				}
			}
			s.push(a[j]);
		}
		while(s.size()){
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
