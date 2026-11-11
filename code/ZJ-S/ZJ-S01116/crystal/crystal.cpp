#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005],cf[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(register int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(n<=30000){
		sort(a+1,a+n+1);
		for(register int i=2;i<=n;i++){
			cf[i]=a[i]-a[i-1];
		}
		int cur=1,mn=0,cnt,mm=m;
		for(register int i=2;i<=n;i++){
			cnt=i;
			cur=1;
			while(m>=cur*cf[cnt]&&cnt<=n){
				m-=cur*cf[cnt];
				cnt++;
				cur++;
			}
			m=mm;
			mn=max(mn,cur);
		}
		cout<<mn;
	}else{
		int ans=1;
		while(m>0){
			if(ans*(a[2]-a[1])<=m){
				ans++;
				m=m-ans*(a[2]-a[1]);
				if(ans==n){
					break;
				}
			}else{
				break;
			}
		}
	cout<<ans;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
