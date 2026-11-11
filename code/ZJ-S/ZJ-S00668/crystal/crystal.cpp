#include<bits/stdc++.h>
using namespace std;
long long l,t,a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	sort(a,a+n);
	long long ans=1;
	for(int i=1;i<n;++i){
		l+=(a[i]-a[i-1])*i;
		if(l>m){
			while(l>m){
				l-=a[i]-a[t++];
			}
		}
		ans=max(ans,i-t+1);
	}
	cout<<max(ans,n-t);
	return 0;
}