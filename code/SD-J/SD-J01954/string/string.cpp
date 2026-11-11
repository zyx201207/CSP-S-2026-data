#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int N=3e5+10;
pair<ULL,char> v[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ULL n,ans=0,len=0;
	scanf("%llu",&n);
	if(n==1){
		printf("0");
		return 0;
	}
	ULL cnt=0;
	for(ULL i=1;i<=n;i++){
		ULL k;char c;
		scanf("%llu %c",&k,&c);
		cnt+=k;
		v[i]={cnt,c};
		len+=k;
	}
	ULL icnt=1,jcnt=n;
	for(ULL i=1,j=len;i<j;i++,j--){
		if(i>v[icnt].first){
			icnt++;
		}
		if(j<v[jcnt-1ull].first+1ull){
			jcnt--;
		}
		if(v[icnt].second!=v[jcnt].second){
			ans++;
		}
	}
	printf("%llu",ans);
	return 0;
}

