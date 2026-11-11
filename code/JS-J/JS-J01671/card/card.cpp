#include<bits/stdc++.h>
#define int long long
using namespace std;

constexpr int z=500009;
int n,m,a[z],ans[z],len,b[z],t[z];

void bf(){
	for(int s=1;s<=n;s++){
//		printf("#%lld\n",s);
		len=0;
		for(int i=s;i<=n;i++){
			if(b[a[i]]&&b[a[i]]<=len)
				len=b[a[i]];
			else
				t[++len]=a[i];
			b[a[i]]=len;
/**			for(int i=1;i<=len;i++)
				printf("%lld ",t[i]);
			puts("");
*/		}
		for(int i=1;i<=m;i++)
			b[i]=0;
		for(int i=1;i<=len;i++)
//			printf("%lld ",t[i]),
			++ans[t[i]];
//		puts("");
	}
}

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    len=n;
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    bf();
    for(int i=1;i<=m;i++)
		printf("%lld ",ans[i]);
}
