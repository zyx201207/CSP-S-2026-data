#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[2005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<0;
	}
	else if(m==2){
		int ans=0;
		int mx=0;
		for(int i=1;i<=n;i++){
			int ans=0;
			for(int j=i+1;j<=n;j++){
				ans+=(a[i]&a[j]);
				mx=max(ans,mx);
			}
		}
		cout<<mx;
	}
	return 0;
}