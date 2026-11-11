#include<bits/stdc++.h>
using namespace std;
stack<int>a;
bool vis[500005],vis1[500005];
long long n,m,b[500005],cnt[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","W",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>b[i];
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			vis[j]=false;
			vis1[j]=false;
		}
		for(int j=i;j<=n;++j){
			if(vis[b[j]]==false){
				a.push(b[j]);
				vis[b[j]]=true;
			}else{
				while(a.top()!=b[j]){
					a.pop();
				}
				a.push(b[j]);
			}
		}
		while(!a.empty()){
			for(int k=1;k<=n;++k){
			    if(a.top()==k&&vis1[k]==false){
				    cnt[k]++;
				    vis1[k]=true;
			    }
			}
			a.pop();
		}
	}
	for(int i=1;i<=m;++i){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
