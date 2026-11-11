#include<bits/stdc++.h>
using namespace std;
queue<int>q;
int n,m,a[500020],mem[500020],ans[500020];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int mx=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans[i]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(mem[a[j]]==0){
				q.push(a[j]);
				mem[a[j]]=1;
			}else{
				while(q.front()!=a[j]){
					mem[q.front()]=0;
					q.pop();
				}
			}
		}
		while(q.size()){
			//cout<<q.front()<<"\n";
			ans[q.front()]++;
			q.pop();
		}
		for(int i=1;i<=m;i++){
			mem[i]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]-1<<" ";
	}
	return 0;
}
