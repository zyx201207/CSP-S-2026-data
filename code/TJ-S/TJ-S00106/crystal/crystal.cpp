#include<bits/stdc++.h>
using namespace std;
long long a[500010]; 
bool cmp(long long x,long long y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	long long maxx=0;;
	sort(a+1,a+n+1,cmp);
	for(long long i=1;i<=n;i++){
		long long x=m;
		long long ans=1;
		for(long long j=i-1;j>=1&&x>=0;j--){
			x-=a[i]-a[j];
			if(x>=0){
				ans++;
			}
		}
		maxx=max(ans,maxx);
	}
	cout<<maxx;
	return 0;
} 
