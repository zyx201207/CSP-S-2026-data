#include<bits/stdc++.h>
using namespace std;
//const int N=1e5*5+1;
//const int M=1e5*3+1;
int n,m,a[5000],ans[3000];
bool vis[3000];
void game(int b){
	stack<int> dt;
	for(int i=b;i<n;i++){
		if(vis[a[i]]){
			while(vis[a[i]]){
				vis[dt.top()]=0;
				dt.pop();
			}
		}
		vis[a[i]]=1;
		dt.push(a[i]);
	}
	while(!dt.empty()){
		ans[dt.top()]++;
		dt.pop();
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
                cin>>a[i];
        }
	for(int i=0;i<n;i++){
		game(i);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
