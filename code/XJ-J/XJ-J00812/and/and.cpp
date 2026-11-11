#include<bits/stdc++.h>
using namespace std;
int n,k,a[200005],ans;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==n){
		ans=a[1];
		for(int i=1;i<=k;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	else{
		if(k==1){
			for(int i=1;i<=k;i++){
				if(ans>a[i]){
					ans=a[i];
				}
			}
			cout<<ans;
			return 0;
		}
		else if(k==2){
			for(int i=1;i<=n;i++){
				int l;
				for(int j=i+1;j<=n;j++){
					l=a[i]&a[j];
					if(l>ans){
						ans=l;
					}
				}
			}
			cout<<ans;
			return 0;
		}
		else{
			sort(a+1,a+n+1,cmp);
			ans=a[1];
			for(int i=1;i<=k;i++){
				ans&=a[i];
			}
			cout<<ans;
		}
	}
	return 0;
}
// 2 10
// 7 111
// 10 1010
//