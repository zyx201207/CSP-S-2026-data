#include <bits/stdc++.h>
#define MAXN 500005
using namespace std;
long long a[MAXN];
long long n,m,ans;
bool cmp(long long A,long long B){
	return A<B;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n>5000){
		for(int i=1;i<=n;i++) cin>>a[i];
		long long k=abs(a[2]-a[1]);
		for(long long i=1;i<=n;i++){
			if(((k+k*i)*i)/2<=m) ans=i; 
			else break;
		}
		cout<<ans+1;
		return 0; 
    }
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		long long sum=0;
		for(int j=1;j<i;j++){
			sum=sum+a[i]-a[j];
		}
		if(sum<=m) ans=max(ans,(long long)i);
	}
	cout<<ans;
	return 0;
} 
