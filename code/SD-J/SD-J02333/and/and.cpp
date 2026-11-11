#include<bits/stdc++.h>
using namespace std;long long n,m,a[200005],ans,mx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans=(i==1?a[i]:ans&a[i]);
		mx=max(mx,a[i]);
	}
	if(n==m){
		cout<<ans;
	}else if(m==1){
		cout<<mx;
	}else{
		sort(a+1,a+n+1,greater<long long>());
		ans=a[1];
		for(int i=2;i<=m;i++){
			ans&=a[i];
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
