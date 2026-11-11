#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],cnt,vis[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	deque<int> q;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cnt=0;
		if(!vis[i]){
			if(vis[a[i]]!=1){
				while(!q.empty()){
					if(q.back()==a[i]){
						q.pop_back();
						q.push_back(a[i]);
						break;
					}
					vis[q.back()]=1;
					q.pop_back();
				}
			}
			q.push_back(a[i]);
			cnt++;
		}
		cout<<cnt<<" ";
	}
	return 0;
}
