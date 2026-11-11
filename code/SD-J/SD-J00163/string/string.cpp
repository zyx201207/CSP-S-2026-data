#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n,a[N];
ll ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf(" %d %c",a+i,c+i);
	for(int i=1,p1=0,j=n,p2=a[j];i<j||(i==j&&p1<p2);){
		int len=min(p2,a[i]-p1);
		p1+=len;
		p2-=len;
		if(c[i]!=c[j]) ans+=len;
		while(p2<=0){
			j--;
			p2+=a[j];
		}
		while(p1>=a[i]){
			p1-=a[i];
			i++;
		}
		//printf("%d %d %d %d\n",i,p1,j,p2);
	}
	printf("%lld",ans);
	return 0;
}
