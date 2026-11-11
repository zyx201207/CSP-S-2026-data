#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a,b;
inline ll read(){
	ll x=0;
	int f=1;
	char ch=getchar();
	while(!isdigit(ch))f=(ch=='-'?-1:1),ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	a=read(),b=read();
	for(int i=1;i<=b;i++)cout<<i<<"\n";
	return 0;
} 
