#include<algorithm>
#include<cmath>
#include<cstdio>
#include<string>
#include<deque>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
#include<list>
using namespace std;
int n,m;
int a[500005];
int ans[300005];
int vis[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	deque<int> q;
	for(int i=1;i<=n;i++){
		if(!q.empty()) q.pop_back();
		for(int j=1;j<=m;j++){
			vis[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				vis[a[j]]=1;
				q.push_back(a[j]);
				ans[a[j]]++;
			}
			else{
				while(!q.empty()&&q.back()!=a[j]){
					vis[q.back()]=0;
					ans[q.back()]--;
					q.pop_back();
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}

