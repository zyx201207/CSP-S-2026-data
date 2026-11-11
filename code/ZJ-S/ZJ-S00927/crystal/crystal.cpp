#include<bits/stdc++.h>
using namespace std;
long long n;
long long m;
long long a[500010];
//long long b[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		//b[i]=b[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	long long s=0;
	long long ans=0;
	long long l=1;
	for(long long i=1;i<=n;i++){
		long long ss;
		//long long mid=(l+i)/2;
		ss=s+(a[i]-a[i-1])*(i-l);
		if(ss<=m){
			ans=max(ans,i-l+1);
			s=ss;
		}else{
			while(ss>m){
				ss=ss-(a[i]-a[l]);
				l++;
			}
			s=ss;
		}
	}
	cout<<ans<<endl;
	return 0;
} 
