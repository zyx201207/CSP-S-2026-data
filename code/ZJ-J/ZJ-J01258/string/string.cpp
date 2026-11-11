#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll a[200005];
ll x,y,ans,e;
char c[200005];
int n,cnt1,cnt2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i],&c[i]);
		a[i]+=a[i-1];
	}
	cnt1=1,cnt2=n;
	x=1;
	y=a[n];
	while(cnt1<cnt2){
		if(c[cnt1]!=c[cnt2]) ans+=min(a[cnt1]-x+1,y-a[cnt2-1]);
		e=min(a[cnt1]-x+1,y-a[cnt2-1]);
		x+=e,y-=e;
		if(x>a[cnt1]) cnt1++;
		if(y<=a[cnt2-1]) cnt2--;
	}
	printf("%lld",ans);
	return 0;
}