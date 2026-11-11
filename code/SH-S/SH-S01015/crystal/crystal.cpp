#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++)
			b[j]=abs(a[i]-a[j]);
		sort(b+1,b+n+1);
		long long cnt=0,s=m;
		for(long long j=1;j<=n;j++){
			if(s>=b[j]){
				s-=b[j];
				cnt++;
			}else
				break;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
