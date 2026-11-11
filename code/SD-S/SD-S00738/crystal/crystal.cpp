#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500010],d[500010],ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long l=0;
	for(long long i=2;i<=n;i++){
		d[i]=d[i-1]+(i-1)*(a[i]-a[i-1]);
		if(d[i]<=m){
			ans=max(ans,(long long)i);
		}else{
			while(d[i]-d[l]-l*(a[i]-a[l])>m){
				l++;
			}
			ans=max(ans,(long long)(i-l));
		}
	}
	cout<<ans;
	return 0;
}
