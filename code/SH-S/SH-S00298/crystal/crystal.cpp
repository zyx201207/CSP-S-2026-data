#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],m,b[500005];
long long ans=-1,d,k;
bool f=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	d=a[2]-a[1];
	for(int i=3;i<=n;i++){
		k=a[i]-a[i-1];
		if(k!=d)f=0;
	}
	if(f){
		ans=1;
		while(m>=k){
			m-=k;
			k+=d;
			ans++;
		}
		cout<<ans<<"\n";
		return 0;
	}
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
	}
	for(int i=1;i<n;i++){
		long long j=i,tmp=m,now=1;
		while(tmp>=now*b[j]&&j<n){
			tmp-=now*b[j];
			j++;now++;
		}
		ans=max(ans,now);
	}
	cout<<ans<<"\n";
	return 0;
}

