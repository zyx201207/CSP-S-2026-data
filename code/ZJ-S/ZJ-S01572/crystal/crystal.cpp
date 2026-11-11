#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],pre[500005];
int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];

	int l=1;
	for(int i=1;i<=n;i++){
		long long sum=a[i]*(i-l+1)-(pre[i]-pre[l-1]);
		while(sum>m){
			sum-=a[i]-a[l];
			l++;
		}
		int num=i-l+1;
		while(sum+(a[i]-a[l-1])<=m && l-1>0){
			num++;
			sum+=a[i]-a[l-1];
			l--;
		}
		ans=max(ans,num);
	//	cout<<i<<' '<<l<<' '<<num<<endl;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
