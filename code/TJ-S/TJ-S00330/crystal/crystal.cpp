#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=2;i<=n;i++){
		long long s=m,cnt=0;
		for(long long j=i-1;j>=1;j--){
			if(s<a[i]-a[j]){
				break;
			}
			s-=(a[i]-a[j]);
			cnt++;
		}
		ans=max(ans,cnt+1);
	}
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}

