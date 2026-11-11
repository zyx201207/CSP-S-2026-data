#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
const int M=3e5+5;
int n,m;
int a[N];
int a_m[M];
bool vis[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	deque<int> q;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int t=1;t<=n;t++){
		memset(vis,false,sizeof(vis));
		for(int i=t;i<=n;i++){
			if(!vis[a[i]]){
				q.push_back(a[i]);
				vis[a[i]]=true;
			}
			else{
				while(q.back()!=a[i]){
					vis[q.back()]=false;
					q.pop_back();
				}
				q.pop_back();
				q.push_back(a[i]);
			}
		}
		while(!q.empty()){
				a_m[q.front()]++;
				q.pop_front();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<a_m[i]<<" ";
	}
	return 0;
}
