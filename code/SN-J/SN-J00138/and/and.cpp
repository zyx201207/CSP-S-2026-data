#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	unsigned long long a[10005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	unsigned long long maxm=-1e6; 
	for(int i=1;i<=n;i++){
		maxm=max(maxm,a[i]);
	}
	int ans=1;
	if(m==1){
		cout<<maxm;
	}else if(m==n){
		for(int i=1;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
			    maxm=max(maxm,a[i]&a[j]);
			}
		}
		cout<<maxm;
	}
	return 0;
}
