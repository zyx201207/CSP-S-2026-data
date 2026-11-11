#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
long long chafen[maxn];
long long num[maxn];
long long amt[maxn],cnt[maxn],stt[maxn],ed[maxn],ans[maxn],qwq,n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=0;i<=n;i++)
		stt[i]=1;
	for(int i=1;i<=n;i++){
	scanf("%lld",&num[i]);		
	}
	sort(num+1,num+1+n);
	for(int i=1;i<=n;i++){
		chafen[i]=num[i]-num[i-1];
	}
	for(int i=1;i<=n;i++){
		cnt[i]=cnt[i-1];
		stt[i]=stt[i-1];
		cnt[i]+=(i-stt[i])*chafen[i];
		while(cnt[i]>m){
			cnt[i]-=(num[i]-num[stt[i]]);
			stt[i]++;
		}
	}
		for(int i=1;i<=n;i++){
			ans[i]=(i-stt[i]+1);
			qwq=max(ans[i],qwq);
		}
		printf("%lld",qwq);
		return 0;
}
