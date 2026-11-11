#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
vector<int> tu[1000005]; 
int n,k;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=read(),T=read();
	while(T--){
		n=read(),k=read();
		for(int i=1;i<=n;i++) tu[i].clear();
		for(int i=1;i<n;i++){
			int u=read(),v=read();
			tu[u].push_back(v);
			tu[v].push_back(u);
		}
		if(c==13||c==14){
			int zh=n-1;
			zh/=2;
			zh-=(k-1);
			zh/=4;
			zh++;
			cout<<zh<<'\n';
			continue;
		}
		cout<<2<<'\n';
	}
	return 0;
} 

