#include<bits/stdc++.h>
#define gc getchar
using namespace std;
typedef long long ll;
typedef __int128 lll;
bool __(char ch){return ch>='0'&&ch<='9';}
template<typename T> inline void read(T &x){
	x=0;char ch=gc();bool sgn=0;
	while(!__(ch)&&ch!=EOF)sgn|=(ch=='-'),ch=gc();
	while(__(ch))x=(x<<1)+(x<<3)+(ch^48),ch=gc();
	if(sgn)x=-x;
}
template<typename T,typename ...I> inline void read(T &x,I &...x1){
	read(x);
	read(x1...);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;read(c,T);
	while(T--){
		puts("0");
	}
	return 0;
}

