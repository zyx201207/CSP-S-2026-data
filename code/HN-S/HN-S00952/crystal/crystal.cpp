#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[500010];
long long s[500010];
long long ans;
long long lb(long long id,long long x){
	long long l=1,r=id;
	while(l<r){
		long long mid=l+r>>1;
		long long c=((id-mid+1)*x)-(s[mid]-s[id+1]);
//		cout<<"id:"<<id<<" x:"<<x<<" c:"<<c<<endl;
		if(c<=m)r=mid;
		else l=mid+1;
	}
	return l;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=n;i>0;i--){
		s[i]=s[i+1]+a[i];
	}
//	for(long long i=1;i<=n;i++)cout<<a[i]<<" ";
//	cout<<endl;
	for(long long i=1;i<=n;i++){
		while(a[i+1]==a[i])i++;
		ans=max(ans,i-lb(i,a[i])+1);
//		cout<<ans<<" ";
	}
//	cout<<endl;
	cout<<ans;
	return 0;
} 
