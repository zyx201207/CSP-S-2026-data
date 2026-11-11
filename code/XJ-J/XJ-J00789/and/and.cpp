#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	if(m==1){
		int ans=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			ans=max(ans,a[i]);
		}cout<<ans;
		return 0;
	}
	int ans=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		
	}
	return 0;
}

