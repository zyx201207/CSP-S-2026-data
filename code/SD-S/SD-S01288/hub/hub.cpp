#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read(){
	ll x=0;char c=getchar();bool f=0;
	for(;c<'0'||c>'9';c=getchar()) f|=(c=='-');
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	return f?-x:x;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	while(1) cout<<"RP++";
	return 0;
} 
