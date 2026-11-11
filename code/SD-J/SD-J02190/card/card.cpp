#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000005],f[1000005],flag=1,st[1000005];
void work(int x){
    bool vis[1000005]={0};
	stack<int> sta;
	for(int i=x;i<=n;i++){
		if(!vis[a[i]]){
		    sta.push(a[i]);
			vis[a[i]]=1;
		}else{
			while(sta.top()!=a[i]){
				vis[sta.top()]=0;
				sta.pop();
			}
		}
	}
	for(int i=1;i<=m;i++){
		f[i]+=vis[i];
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			flag=0;
		}
	}
	if(flag){
		for(int i=2;i<=n;i++){
			if(a[i]!=a[i-1]){
				cout<<i-1<<" ";
			}
		}
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		work(i);
	}
	for(int i=1;i<=m;i++){
		cout<<f[i]<<" ";
	}
	return 0;
}
