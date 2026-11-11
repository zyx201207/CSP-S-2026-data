#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],f[200010],k[25],ans2;
bool cmp(int a,int b){
	return a>b;
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}else if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					ans=max(ans,(a[i]&a[j]));
				}
			}
		}
		cout<<ans;
	}else if(m==n){
		int ans=a[1];
		for(int i=1;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}else if(n<=20){
		sort(a+1,a+n+1,cmp);
		int ans=a[1];
		for(int i=1;i<=m;i++){
			ans&=a[i];
		}
		cout<<ans;
	}else{
		cout<<0;
	}
}
