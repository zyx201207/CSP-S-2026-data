#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],sum,t,o=1;
long long g(int x){
	long long ans=0;
	for(int i=x;i>=1;i--){
		ans+=(a[x]-a[i]);
		if(ans>m){
			return i-x;
		}
	}
	return x;
} 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==2){
			t=a[2]-a[1];
		}if(o==1&&a[i]-a[i-1]!=t){
			o=0;
		}
	}
	if(o==1){
		long long ans=0;
		for(int i=2;i<=n;i++){
			ans+=(i-1)*t;
			if(ans>m){
				cout<<i-1;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		while(a[i]==a[i+1])i++;
		sum=max(g(i),sum);
	}
	cout<<sum;
	return 0;
}
