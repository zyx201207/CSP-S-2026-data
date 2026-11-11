#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200001],ans;
char c[200001];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d %c",&a[i],&c[i]);
	int p=1,q=0,m=0;
	for(int i=1;i<=n;i++){
		m=a[i];
		while(p<=n&&a[n-p+1]-q<=m){
			if(c[n-p+1]!=c[i])ans+=a[n-p+1]-q;
			m-=a[n-p+1]-q;p++;q=0;
		}
		if(m!=0){
			if(c[n-p+1]!=c[i])ans+=m;
			q+=m;m=0;
		}
	}
	if(p!=n+1||m!=0||q!=0)printf("p=%lld,m=%lld,q=%lld",p,m,q);
	else printf("%lld",ans/2);
	return 0;
}

