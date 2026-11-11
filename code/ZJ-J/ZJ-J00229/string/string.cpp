#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200001];
char c[200001];
char qwq,awa;
int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;++i){
		scanf("%lld",a+i);
		getchar();
		scanf("%c",c+i);
		getchar();
	}
	long long cnt1=1,cnt2=n;
	long long ans=0;
	while(cnt1<cnt2){
		if(!a[cnt1])cnt1++;
		if(!a[cnt2])cnt2--;
		long long mm=min(a[cnt1],a[cnt2]);
		if(c[cnt1]!=c[cnt2]){
			ans+=mm;
		}
		a[cnt1]-=mm,a[cnt2]-=mm;
	}
	printf("%lld",ans);
}
