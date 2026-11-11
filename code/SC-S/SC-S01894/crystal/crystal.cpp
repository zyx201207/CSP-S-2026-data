#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
int cnt[500005];
int main(){
	freopen("crystal","r",stdin);
	freopen("crystal","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	long long max_cnt=-0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		cnt[a[i]]++;
		if(cnt[a[i]]>max_cnt){
			max_cnt=cnt[a[i]];
		}
	}
	if(m==0){
		printf("%lld",max_cnt);
		return 0;
	}
    bool flag=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=i) flag=0;
	}
	long long da=0;
    	if(flag){
		long long sum=0;
	    for(int i=1;i<=n;i++){
			sum+=i;
			long long sum1=0;
		    if(m==sum){
				for(int j=0;j<=m;j++){
				    sum1+=j;
					if(sum1==m) da=j+1;
				}
			}else{
				for(int j=0;j<=m;j++){
					sum1+=j;
					if(sum1<m&&sum1-m<(j+1)) da=j+1;
				}
			}
		}
		printf("%lld",da);
		return 0;
	}
	return 0;
}