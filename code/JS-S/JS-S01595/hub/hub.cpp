#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long s=0,b=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')b=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=(s<<3)+(s<<1)+(c^48);c=getchar();}
	return s*b;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	return 0;
}
