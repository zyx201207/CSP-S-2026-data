#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],ans=1,sum,head=1,tail;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	for(long long i=2;i<=n;i++){
		sum+=b[i]*(i-head);
		while(sum>m){
			sum-=(a[i]-a[head]);
			head++;
		}
		ans=max(ans,i-head+1);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

