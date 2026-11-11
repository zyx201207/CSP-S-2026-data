#include<bits/stdc++.h>
using namespace std;
long long a[100000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,m,num=0;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long k=n/2+n%2-1;
	long long x=a[k+1];
		long long c=x-a[1];
		long long d=a[n]-x;
		if(c<=d){
			for(long long j=k;j<=k;j--){
			long long y=x-a[j];
			if(m>=y){
			m-=y;
			a[j]=x;	
			}
			else {
				for(long long i=1;i<=n;i++){
					if(a[i]==x) num++;
				}
				cout<<num;
					return 0;
			}
		}
		}
		else{
			for(long long j=n-1;;j--){
				long long y=a[n]-a[j];
				if(m>=y){
					m-=y;
					a[j]=a[n];
				}
				else{
					for(long long i=1;i<=n;i++){
					if(a[i]==a[n]) num++;
				}
				cout<<num;
					return 0;
				}
			}
		}
	return 0;
}