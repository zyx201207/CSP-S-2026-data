//黄伟豪 西安市铁一中学 SN-J00649 
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005]={0};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n&&i!=j;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		int s=0;
		s=a[1];
		for(int i=2;i<=n;i++){
			s&=a[i];
		}
		for(int i=1;i<=n;i++){
			ans=max(ans,s|a[i]);
		}
		cout<<ans;
		return 0;
	}
	ans=a[n];
	for(int i=n-1;i>=n-m+1;i--){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}
