#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],s,b[500010],d[500010];
bool check(long long x,long long y){
	if(((d[y]-d[y-x]-((y-1-x)*(b[y]-b[y-x]))))<=m){
		return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1); 
	for(long long i=2;i<=n;i++){
		b[i]=b[i-1]+(a[i]-a[i-1]);
		d[i]=d[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	for(long long i=2;i<=n;i++){
		long long l=1,r=i-1;
		while(l<=r){
			
			long long mid=(l+r)/2;
			if(check(mid,i)){
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		s=max(s,r+1);
	}
	cout<<s;
	return 0;
} 