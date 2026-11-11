#include<bits/stdc++.h>
using namespace std;
#define MAXN int(5e5+1000)
#define MAXM int(3e5+1000)
#define ll long long
int n,m;
int a[MAXN];
int cnt[MAXM];
bool vis[MAXM];
stack<int> q;
void game(int NowN){
	memset(vis,false,sizeof(vis));
	for(int i=NowN;i<=n;i++){
		if(vis[a[i]]==true){
			while(true){
				if(q.top()==a[i]){
					vis[q.top()]=false;
					q.pop();
					break;
				}
				vis[q.top()]=false;
				q.pop();
			}
			vis[a[i]]=true;
			q.push(a[i]);
		}else{
			vis[a[i]]=true;
			q.push(a[i]);
		}
	}
	while(!q.empty()){
		cnt[q.top()]++;
		q.pop();
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		game(i);
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
