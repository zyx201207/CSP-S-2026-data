#include<bits/stdc++.h>
using namespace std;

int n;
long long a[200105];
char c[200105];
long long sum = 0;
long long s[200105];//总前缀和 
long long ans = 0;
long long pre[26][200105];//字母前缀和 
long long llen;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i<=n;i++){
		scanf("%lld %c",&a[i],&c[i]);
		s[i] = s[i-1]+a[i];
		for(int j = 0;j<=25;j++){
			if(j+'a'==c[i])pre[c[i]-'a'][i] = pre[c[i]-'a'][i-1]+a[i];
			else{
				pre[c[i]-'a'][i] = pre[c[i]-'a'][i];
			}
		}
		llen+=a[i];
	}
	for(int i = 1;i<=n;i++){
		sum+=a[i];
		if(sum*2>llen){
			long long rr = llen-sum+a[i];//个数上的 
			long long ll = llen-sum+1;
			int l = lower_bound(s+1,s+1+n,ll)-s;//下标 
			int r = lower_bound(s+1,s+1+n,rr)-s;//下标 
			ans+=rr-ll+1-pre[c[i]-'a'][r]+pre[c[i]-'a'][l-1];
			if(c[r]==c[i]){
				ans+=s[r]-rr;
			}
			if(c[l]==c[i]){
				ans-=ll-s[l-1]-1;
			}
//			printf("%d %d %d %d %d\n",l,r,ll,rr,ans);
		}
	}
	printf("%lld",ans);
	return 0;
}
