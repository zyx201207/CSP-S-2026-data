#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],ans,ma; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		long long x=m;
		ans=0;
		for(int j=i;j>=1;j--){
			x-=(a[i]-a[j]); 
			if(x>=0)ans++;
			else break;
		}
		ma=max(ma,ans);
		if(ma>=i)break;
	}
	cout<<ma;
	return 0;
}