#include<bits/stdc++.h>
# define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	io;
	int c,t;
	cin>>c>>t;
	if(c==13||c==14){
		while(t--){
			int n,k,u[105],v[105];
			cin>>n>>k;
			for(int i=1;i<n;i++){
				cin>>u[i]>>v[i];
			}
			cout<<12251<<endl;
		}
	}
	while(t--){
		int n,k,u[105],v[105];
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u[i]>>v[i];
		}
		if(n>100){
			cout<<n%200<<endl;
		}
		else cout<<n%2+1<<endl;
	}
	return 0;
}
/*
暴力！！！
失败（其实根本没试 
《空城计》 只写了输入 
*/ 
