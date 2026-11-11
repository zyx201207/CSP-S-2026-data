#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
long long cnt[300005];
queue<int> p,q;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=600){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				while(!q.empty()){
					if(q.front()==a[j]) break;
					p.push(q.front());
					q.pop();
				}
				while(!q.empty()){
					q.pop();
				}
				p.push(a[j]);
				while(!p.empty()){
					q.push(p.front());
					p.pop();
				}
			}
			while(!q.empty()){
				cnt[q.front()]++;
				q.pop();
			}
		}
		for(int i=1;i<=m;i++){
			cout<<cnt[i]<<" ";
		}
		return 0;
	}
	else{
		for(int i=1;i<=m;i++) cnt[i]=1;
		for(int i=1;i<=n;i++){
			if(a[i]==a[i+1]) cnt[a[i]]++;
			else{
				cnt[a[i+1]]+=cnt[a[i]];
			}
		}
		for(int i=1;i<=m;i++){
			cout<<cnt[i]<<" ";
		}
	}
	return 0;
}
