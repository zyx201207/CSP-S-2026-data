#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N],ans=1;
int n,m,p,s[N][25];
bool f[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=36;i++)ans*=2;
	ans--;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		long long cnt=a[i];int st=0;
		while(cnt){
			++st;
			if(cnt&1)s[i][st]=1;
			cnt>>=1;
		}
		p=max(p,st);
	}
	m=n-m;
	for(int i=p;i>=1;i--){
		int cnt=0;
		for(int j=1;j<=n;j++)
			if(!f[j]&&s[j][i]==0)cnt++;
		if(m>=cnt){
			m-=cnt;
			for(int j=1;j<=n;j++)
				if(!f[j]&&s[j][i]==0)f[j]=true;
		}
	}
	for(int i=1;i<=n;i++)
		if(!f[i])ans&=a[i];
	printf("%lld\n",ans);
	return 0;
}
