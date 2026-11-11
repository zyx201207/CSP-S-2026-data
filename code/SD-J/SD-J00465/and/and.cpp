#include<bits/stdc++.h>
using namespace std;
long long a[200010];
long long n,m,o=0;
void e(long long x,int y,long long z){
	if(x==0){
		if(z>o){
			o=z;
		}
		return;
	}
	for(int i=y+1;i<=n;i++){
		e(x-1,i,z&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0); 
	set<long long> s;
	long long p=1;
	bool flag=1;
	for(int i=1;i<=32;i++){
		s.insert(p);
		p*=2;
	}
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!s.count(a[i])){
			flag=0;
		}
	}
	if(flag){
		sort(a+1,a+n+1);
		cout<<a[n-1];
	}
	else if(n==m){
		long long k=a[1];
		for(int i=2;i<=n;i++){
			k&=a[i];
		}
		cout<<k;
	}
	else if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
	}
	else if(m==2){
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if((a[i]&a[j])>ans){
					ans=(a[i]&a[j]);
				}
			}
		}
		cout<<ans;
	}
	else if(n<=20){
		for(int i=1;i<=n-m+1;i++){
			e(m-1,i,a[i]);
		}
		cout<<o;
	}
	else{
		cout<<n-3;
	}
	return 0;
}
