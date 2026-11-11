#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
//根本不会 
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	return 0;
}

