#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200006],ans=-1;;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]&0);
		}
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					ans=max(a[i]&a[j],ans);
				}
			}
		}
	}
	else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
	}
	cout<<ans;
	return 0;
}
//梦限大和母鸡卡不看后悔一辈子； 
