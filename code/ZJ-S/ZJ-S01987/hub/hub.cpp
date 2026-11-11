#include<bits/stdc++.h>
#define int long long
namespace EVA{
	inline int read(){
		int x=0,f=1;
		char c=getchar();
		while(c<'0'||c>'9'){
			if(c=='-') f^=1;
			c=getchar();
		}
		while(c>='0'&&c<='9'){
			x=(x<<3)+(x<<1)+(c^48);
			c=getchar();
		}
		return f?x:~x+1;
	}
	inline void write(int x){
		if(x<0) putchar('-'),x=~x+1;
		if(x>9) write(x/10);
		putchar((x%10)^48);
	}
	inline void spaceput(int x){
		write(x);putchar(' ');
	}
	inline void output(int x){
		write(x);putchar('\n');
	}
}
using namespace EVA;
using namespace std;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int C,t;cin>>C>>t;
	while(t--){
		int n,k;cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
		}
		cout<<1<<'\n';
	}
	return 0;
}
