#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int l=0;
			for(int k=i;k<=j;k++){
				l+=a[k];
			}
			if((l+m)/(j-i)==a[j]) ans=max(ans,j-i);
		} 
	}
	cout<<ans;
	return 0;
} 
