#include <bits/stdc++.h>
using namespace std;
long long n,m,mx;
long long a[500005];
bool dc(){
	for(int i=1;i<n-1;i++){
		if(a[i+1]-a[i]!=a[i+2]-a[i+1])return 0;
	}
	return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(dc()){
		long long s2=0;
		for(int i=1;i<=n;i++){
			s2+=a[i];
			if(a[i]*i-s2>=m){
				cout<<mx;
				return 0;
			}
			mx=max(mx,(long long)i);
		}
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		long long s=0;
		for(int j=i;j<=n;j++){
			s+=a[j];
			if(a[j]*(j-i+1)-s>=m)break;
			mx=max(mx,(long long)(j-i+1));
		} 
	}
	cout<<mx;
	return 0;
}
