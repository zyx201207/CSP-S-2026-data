#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
inline long long read(){
	long long res=0,f=1;char g=getchar();
	while(g<'0'||g>'9'){if(g=='-'){f=-1;}g=getchar();}
	while(g>='0'&&g<='9'){res=(res<<3)+(res<<1)+g-48;g=getchar();}
	return res*f;
}
long long a[500010];
queue <long long> h;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	long long cnt=0;
	long long ans=1,ff=1;
	h.push(a[1]);
	for(int i=2;i<=n;i++){
		cnt+=(a[i]-a[i-1])*ff;
		//printf("%d %d\n",i,cnt);
		while(!h.empty()&&cnt>m){
			int u=h.front();
			cnt-=a[i]-h.front();
			h.pop();
			ff--;
		}
		h.push(a[i]);
		ff++;
		ans=max(ans,ff);
	}
	printf("%lld",ans);
	return 0;
}

