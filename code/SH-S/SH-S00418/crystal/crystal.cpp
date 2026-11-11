#include <bits/stdc++.h>
using namespace std;

long long n,m;
long long a[500050];
int ans;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++) cin >> a[i];
	sort(a,a+n);
	long long now=0;
	for(int i=0,j=0;j<n;){
		while(++j){
			if(j==n) break;
			now+=(j-i)*(a[j]-a[j-1]);
			if(now>m) break;
		} 
		ans=max(ans,j-i);
		while(++i){
			if(i==n) break;
			now-=(a[j]-a[i-1]);
			if(now<=m) break;
		}
		ans=max(ans,j-i+1);
	} 
	cout<<ans;
	return 0;
}
