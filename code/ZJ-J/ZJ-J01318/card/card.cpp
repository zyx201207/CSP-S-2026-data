#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],mapp[N],ans[N];
bool vis[N];
stack<int>s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==false){
				s.push(a[j]);
				vis[a[j]]=true;
				mapp[a[j]]=s.size();
			}
			else{
				int size=s.size();
				for(int k=1;k<=size-mapp[a[j]];k++){
					vis[s.top()]=false;
					s.pop();
				}
				
			}
		}
		while(!s.empty()){
			ans[s.top()]++;
			vis[s.top()]=false;
			mapp[s.top()]=0;
			s.pop();
		}
		memset(vis,0,sizeof(vis));
		memset(mapp,0,sizeof(mapp));
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}