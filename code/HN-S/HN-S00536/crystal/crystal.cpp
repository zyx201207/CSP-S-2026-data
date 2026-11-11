#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],d[500005],ans=1,maxx;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		d[i]=a[i]-a[i-1];
	}
	for(int i=2;i<=n;i++){
		if(m>=d[i]){
			ans++;
			m-=d[i];
		}else{
			maxx=max(maxx,ans);
			ans=1;
		}
	}
	cout<<maxx;
	return 0;
}
