#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long a[500005],c[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int A=1,B=1;
	a[0]=1;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			A=0;
		}
		if(i>2){
			if(a[i]!=a[i-1]+a[2]-a[1]){
				B=0;
			}
		}
		
	}
	if(A){
		long long num=0,i=1;
		while(num+i<=m){
			num+=i;
			i++;
		}
		cout<<i;
		return 0;
	}
	if(B){
		long long num=0,i=1;
		while(num+a[2]-a[1]<=m){
			num+=a[2]-a[1];
			i++;
		}
		cout<<i;
		return 0;
	}
	sort(&a[1],&a[n+1]);
	long long ans=0;
	for(long long i=1;i<=n;i++){
		long long num=0;
		long long an=1;
		for(long long j=i-1;j>=1;j--){
			if(num+a[i]-a[j]<=m){
				num+=a[i]-a[j];
				an++;
			}else{
				break;
			}
		}
		ans=max(ans,an);
	}
	cout<<ans;
	return 0;
}