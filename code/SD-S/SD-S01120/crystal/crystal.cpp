#include<bits/stdc++.h>
using namespace std;
long long n,l,m,ans=-1,num,a[500010],c[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++) c[i]=a[i+1]-a[i];
	l=1;
	for(int i=1;i<=l&&l<n;i++){
		while(num<=m&&l<n){
			num+=c[l]*(l-i+1);
			l++;
		}
		l--;
		ans=max(ans,l-i+1);
		num-=c[l]*(l-i+1);
		num-=(a[l]-a[i]);
	}
	cout<<ans;
	return 0;
} 
//rp+++
