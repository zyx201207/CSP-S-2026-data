#include <bits/stdc++.h>
using namespace std;
int n,a[200005];
long long cnt,ans;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%c%c%c",&a[i],&c,&s[i],&c);
		cnt += a[i];
	}
	long long l = 1,r = cnt,z = 1,y = n;
	while(l < r){
		int z1 = z,y1 = a[y],minj = min(a[z],a[y]);
		if(s[z] != s[y]) ans += minj;
		l += minj,r -= minj;
		if(a[z] <= a[y]) a[y]-=a[z],z++;
		if(y1 <= a[z1]) a[z1]-=y1,y--;
		
	}
	printf("%lld",ans);
	return 0;
}
