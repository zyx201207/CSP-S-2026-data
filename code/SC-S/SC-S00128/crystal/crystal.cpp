#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long mx=0;
long long a[50005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(long long i=0;i<n;i++){
		long long cnt=0;
		for(long long j=0;j<=i;j++){
			long long c;
			long long mm=m;
			c=a[i]-a[i-j];
			if(c<=mm){
				mm-=c;
				cnt++;
			}else{
				break;
			}
		}
		mx=max(mx,cnt);
	}
	cout<<mx;
	return 0;
}