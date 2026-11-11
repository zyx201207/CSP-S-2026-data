#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[500005],h[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a+0,a+n);
	h[0]=0;
	for(long long i=1;i<n;i++){
		h[i]=h[i-1]+a[i]-a[i-1];
	}
	for(long long i=0;i<n;i++){
		for(long long j=0;j<=i;j++){
			if(m>=h[i]-h[j-1]){
				ans=max(ans,i-j+1);
				break;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
