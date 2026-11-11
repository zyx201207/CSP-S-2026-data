#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <queue>

using namespace std;
typedef long long ll;

inline ll readl(){
	ll x=0,y=1;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') y=-y;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c-'0');
		c=getchar();
	}
	return x*y;
}

void writel(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x+'0');
	else writel(x/10),putchar(x%10+'0');
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	writel(readl()+readl());
	fclose(stdin);
	fclose(stdout);
	return 0;
}
