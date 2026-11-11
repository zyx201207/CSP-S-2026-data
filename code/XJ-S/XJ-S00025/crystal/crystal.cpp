#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long int sum[N],a[N],n,m,ans,mid,b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=i*a[i];
	}
	sort(a+1,a+n+1);
	for(long long int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(long long int i=1;i<=n;i++){
		sum[i]=sum[i]+m;
		if(sum[i]<b[i]){
			ans=i;
			break;
		}
	}
	cout<<ans-1;
	return 0;
}
