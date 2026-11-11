#include<bits/stdc++.h>
using namespace std;
long long n,a[10000005],ans;
unsigned long long m,k;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=n;i>=1;i--){
		k=0;
		for(long long j=i-1;j>=1;j--){
			k+=a[i]-a[j];
			if(k>m){
				ans=max(ans,i-j);
				break;
			}else if(k==m){
				ans=max(ans,i-j+1);
				break;
			}else if(k<m&&j==1){
				ans=max(ans,i-j+1);
			}
		}
	}
	cout<<ans;
	return 0;
}