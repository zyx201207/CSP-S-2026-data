#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n]; 
		return 0;
	}else{
		long long ans=-1000000;
		for(long long i=1;i<=n;i++){
			long long x=a[i]&a[i+1],mm=m-2,cnt=m+2;
			while(mm--){
				x=x&a[cnt];
				cnt++;
			}
			ans=max(ans,x);
		}
		cout<<ans;
	}
	return 0;
}
