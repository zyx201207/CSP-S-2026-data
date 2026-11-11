#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int ans=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		ans=ans*10+ch-'0';
		ch=getchar();
	}	
	return f*ans;
}
const int N=505;
vector<int> g[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	return 0;
}
