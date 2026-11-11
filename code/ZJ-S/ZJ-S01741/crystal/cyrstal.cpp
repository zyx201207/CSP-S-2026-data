#include<bits/stdc++.h>
using namespace std;
int n,m,a[500100],ans,r=1,b[500100],c;
int main(){
	freopen("crystal4.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	for(int i=1;i<=n;i++){
		int e=b[i]*(i-r);
		if(c+e<=m){
			c+=e;
			ans=max(ans,i-r+1);
		}
		else{
			c-=a[i-1]-a[r];
			r++;
			i--;
		}
	}
	cout<<ans;
	return 0;
}
