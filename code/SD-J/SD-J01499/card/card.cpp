#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m;
int a[N];
deque<int> q;
bool flag[M];
int ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(flag,0,sizeof flag);
		for(int j=i;j<=n;j++){
			while(!q.empty()&&flag[a[j]]){
				flag[q.back()]=0;
				q.pop_back();
			}
			flag[a[j]]=1;
			q.push_back(a[j]);
		}
		while(!q.empty()){
			ans[q.front()]++;
			q.pop_front();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

