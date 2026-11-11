#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=n,sum=0;sum<a[i]&&j>i;j--){
			if(sum+a[j]<=a[i]){
				sum+=a[j];
				n--;
				if(c[i]!=c[j]){
					ans+=a[j];
				}
			}
			else{
				a[j]-=a[i]-sum;
				if(c[i]!=c[j]){
					ans+=a[i]-sum;
				}
				sum=a[i];
			}
		}
	}
	cout<<ans;
	return 0;
}
