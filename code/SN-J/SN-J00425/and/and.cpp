#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[212345];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int maxn=0;
		for(int i=1;i<=n;i++){
			maxn=max(a[i],maxn);
		}
		cout<<maxn;
	}
	else if(m==2){
	int maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					int asb=a[i]&a[j];
					maxn=max(asb,maxn);
				}
			}
		}
		cout<<maxn;
	}
	else if(m==n){
	int maxn=a[1];
		for(int i=1;i<=n;i++){
			maxn&=a[i];
		}
		cout<<maxn;
	}
	else if(m==n-1){
		int maxn=0;
		for(int i=1;i<=n;i++){
			int man=0;
			if(i==n){
				maxn=a[i-1];
			}
			else{
				maxn=a[i+1];
			}
			for(int j=1;j<=n;j++){
				if(a[j]!=a[i]){
					man&=a[j];
				}
			}
			maxn=max(man,maxn);
		}
		cout<<maxn;
	}
	
	else if(m==3){
		int maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(a[i]!=a[j]&&a[j]!=a[k]&&a[i]!=a[k]){
						maxn=max(maxn,a[i]&a[j]&a[k]);
					}
				}
			}
		}
		cout<<maxn;
	}
}	
