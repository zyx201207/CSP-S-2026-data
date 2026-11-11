#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n],b[31],r,c[m];
	b[0]=1;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		int ans=0;
		for(int i=0;i<n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}else if(m==n){
		for(int i=1;i<n;i++){
			a[0]&=a[i];
		}
		cout<<a[0];
	}
	return 0;
}
