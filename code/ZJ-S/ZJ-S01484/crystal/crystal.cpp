#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=0,cnt=0,x,bcd,idx;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)scanf("%lld",&a[i]);
	bool flag=true;
	long long c=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=c){
			flag=false;
			break;
		}
	}
	if(flag==true){
		long long cnt=1;
		for(int i=1;;i++){
			m-=(c*i);
			if(m<0)break;
			cnt++;
		}
		printf("%lld",cnt);
		return 0;
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		cnt=1;
		x=m;
		bcd=a[i];
		idx=i;
		++i;
		for(i;i<=n,a[i]==bcd;i++){
			cnt++;
		}
		i--;
		for(int j=idx-1;j>=1;j--){
			x=x-(bcd-a[j]);
			if(x<0){
				break;
			}
			cnt++;
		}
		ans=max(ans,cnt);
	}
	printf("%lld",ans);
	return 0; 
} 
