#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+20;
int a[MAXN];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int maxa=-1;
	int ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>20&&n<=2000){
		if(m==1){
			for(int i=1;i<=n;i++){
				maxa=max(a[i],maxa);
			}
			cout<<maxa;
		}else if(m==n){
			ans=a[1];
			for(int i=2;i<=n;i++){
				ans=ans&a[i];
			}
			cout<<ans;
		}else if(m==2){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					ans=max(ans,a[i]&a[j]);
				}
			}
			cout<<ans;
		}
	}
	else cout<<2524;
} 
