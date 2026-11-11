#include<bits/stdc++.h>
using namespace std;
#define N 500010
long long n,m;
long long a[N],s[N],cnt,num,ans,u[N]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//等差数列 
	long long d=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]==d){
			ans++;
		}
	}
	if(ans==n-1){
		for(int i=1;i<=n;i++){
			u[i]+=u[i-1]+(i-1)*d;
		}
		for(int i=1;i<=n;i++){
			if(m<u[i]){
				cout<<i-1;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	//普通 
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]-a[i-1]>m){
			num++;
		}
	}
	if(num==n){
		cout<<"1";
		return 0;
	}
	long long q=a[(n+1)/2];
	for(int i=1;i<=n;i++){
		s[i]=abs(a[i]-q);
	}
	sort(s+1,s+n+1);
	for(int i=1;i<=n;i++){
		if(m-s[i]>=0){
			cnt++;
			m-=s[i];
		}
	}
	cout<<cnt;
} 
