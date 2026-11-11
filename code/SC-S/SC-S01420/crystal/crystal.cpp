#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt,ans;
long long a[500005],s[500005];
bool fa,fb;
long long go(long long n){
	long long anss=0;
	for(int i=n-1;i>=1;i--){
		anss+=(a[n]-a[i]);
		if(anss>m){
			return n-i;
		}
	}
	return n;
}
long long check(long long x){
	long long id=n,sum=0;
	for(int i=1;i<=n;i++){
		if(a[i]>x){
			id=i-1;
			break;
		}
	}
	for(int i=id-1;i>=1;i--){
		sum+=(a[id]-a[i]);
		if(sum>m){
			return id-i;
		}
	}
	return id;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long num=0; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			fa=1;
		}
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[2]-a[1]){
			fb=1;
		}
	}
	for(int i=1;i<=n;i++){
		num+=a[n]-a[i]; 
	}
	if(num<=m){
		cout<<n;
		return 0;
	}
	if(fa==0||fb==0){
		num=0;
		for(int i=1;i<=n;i++){
			num+=(a[2]-a[1])*i;
			if(num>m){
				cout<<i;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	if(a[n]<=100){
		long long anss=0;
		for(int i=a[n];i>=a[1];i--){
			anss=max(anss,check(i));
		}
		cout<<anss;
		return 0;
	}
	long long anss=0;
	for(int i=n;i>=anss;i--){
		anss=max(anss,go(i));
	}
	cout<<anss;
	return 0;
} 