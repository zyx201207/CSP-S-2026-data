#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[100005],mx=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]>mx){
				mx=a[i];
			}
		}
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=m;j++){
				int t=(a[i]|a[j]);
				if(t>mx){
					mx=t;
				}
			}
		}
	}
	cout<<mx;
	return 0;
} 
