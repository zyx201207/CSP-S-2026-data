#include<bits/stdc++.h>
using namespace std;
int a[300005];
int ans[300005]; 
int c[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	for(int i=n;i>=1;i--){
		a[c[i]]=i;
	}
	for(int i=1;i<=n;i++){ 
	bool flag=0;
		for(int j=n;j>=i;j--){
			ans[c[j]]++;
			if(a[c[j]]!=j&&a[c[j]]>=i){
				flag=1;
				break;
			}
		}
		if(flag==1) continue;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
