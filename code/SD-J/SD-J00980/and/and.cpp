#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int n,m,res,ans;
int maxx;
int a[200100];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			ans=a[i];
		}else ans&=a[i];
		maxx=max(maxx,a[i]);
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	if(m==n){
		cout<<ans;
		return 0;
	}
	res=a[1]&a[2];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			res=max(res,a[i]&a[j]);
		}
	}
	cout<<res;
	return 0;
}
