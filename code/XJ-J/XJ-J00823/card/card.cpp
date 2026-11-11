#include<bits/stdc++.h> 
using namespace std;
int n,m,a[50005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		int ans=0;
		for(int j=1;j<=n;j++){
			int f=0;
			for(int k=j;k<=n;k++){
				if(a[k]==i){
					f++;
					break;
				}
			} 
			if(f>0) ans++;
		}
		cout<<ans<<" ";
	}
	return 0;
}
