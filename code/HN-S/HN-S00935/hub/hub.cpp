#include<bits/stdc++.h>
using namespace std;
#define debug(a) cout<<#a<<": "<<a<<endl;

inline void read(int& x){
	char ch=getchar();int f=1;x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())x=(x<<3)+(x<<1)+(ch^48);
	x*=f;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	// CSP-J/S RP++!!!
	return 0;
}
