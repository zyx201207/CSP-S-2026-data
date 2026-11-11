#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long n,m;
long long sum=0;
long long ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum+=a[i];
		long long now=a[i]*i-sum;
		if(now<=m) ans++;
		else break;
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
