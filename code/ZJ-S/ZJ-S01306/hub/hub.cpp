#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace my{
	inline int read(){
		int c=getchar(),f=1,s=0;
		while(c<'0'||c>'9'){
			if(c=='-') f=-1;
			c=getchar();
		}
		while(c>='0'&&c<='9'){
			s=s*10+(c^48);
			c=getchar();
		}
		return f*s;
	}

	signed main(){
		
		return 0;
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	return my::main();
}

