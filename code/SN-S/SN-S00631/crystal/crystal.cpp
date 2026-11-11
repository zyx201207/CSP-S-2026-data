#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500050],b[500050],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (int i=n;i>=1;i--){
		for (int j=1;j<=i;j++){
			b[j]=a[j]-a[j-1];
		}
		long long p=m,qw=2,sum=0;
		while(p>=0){
			p=p-b[qw];
			qw++;
			sum++;
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
