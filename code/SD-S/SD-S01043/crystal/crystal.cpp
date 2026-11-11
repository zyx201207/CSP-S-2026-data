#include<bits/stdc++.h>
using namespace std;
int n,ans,l=1;
long long m,a[500005];
unsigned long long p;
int main(){
	ios::sync_with_stdio(),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	a[0]=a[1];
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]){
			p=p+(a[i]-a[i-1])*(i-l);
		}
		while(p>m&&l<=i){
			p=p-a[i]+a[l];
			l++;
		}
		ans=max(i-l+1,ans);
	}
	cout<<ans;
	return 0;
}
