#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],cf[500005],ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		long long tmp=0;
		while(tmp+a[i]-a[i-cf[i]]<=m&&cf[i]<i){
			tmp=tmp+a[i]-a[i-cf[i]];
			cf[i]++;
		}
	}
	for(int i=2;i<=n;i++) ans=max(ans,cf[i]);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
