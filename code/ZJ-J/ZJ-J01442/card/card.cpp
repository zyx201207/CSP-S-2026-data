#include<bits/stdc++.h>
using ll=long long;
using namespace std;
int a[500005];
int v[300005];
int cnt[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	stack<int> q;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(v[a[j]]!=0){
				while(q.top()!=a[j]&&!q.empty()){
					int d=q.top();
					v[d]=0;
					q.pop();
				}
			}
			else{
				q.push(a[j]);
				v[a[j]]=1;
			}
		}
		while(!q.empty()){
			int d=q.top();
			cnt[d]++;
			v[d]=0;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	
	
	return 0;
}