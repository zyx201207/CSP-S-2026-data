#include<bits/stdc++.h>
using namespace std;
int a[50005];
int main(){
//freopen("string.in","r",stdin);
//freopen("string.out","w",stdout);
	int a,t;
	cin>>a>>t;
	for(int i=1;i<=1;i++){
		cin<<a[i];
		maxn=max(maxn,a[i]);
	}
	int n,ans=0;
	cin>>n;
	if(a==n){
		fot(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
	}
	cout<<ans;



	return 0;
}

