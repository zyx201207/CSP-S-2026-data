#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int N=2e5+10;
int n,a[N],p;
char s[1],c[N];
ll ans;
int main(){
	freopen("string.in","r",stdin),freopen("string.out","w",stdout);
	scanf("%d",&n),p=n-1;
	for(int i=0;i<n;i++)scanf("%d",&a[i]),scanf("%s",s),c[i]=s[0];
	for(int i=0;i<n;i++){
		while(i<p&&a[i]>=a[p])ans+=a[p]*(c[i]!=c[p]),a[i]-=a[p],p--;
		if(i==p)break;
		a[p]-=a[i],ans+=a[i]*(c[i]!=c[p]);
	}
	printf("%lld",ans);
	return 0;
}
//大家好,我有志于进入迷惑行为大赏。
