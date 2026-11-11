#include<bits/stdc++.h>

using namespace std;
const int N=2e5+7;
int n,m;
int a[N],ans[N],f[N];
int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		f[1]=f[2]=0;
		for(int j=n;j>=i;j--){
			if(a[j]==a[i]){
				ans[a[j]]++;
				if(j!=n){
					if(a[j]==1) ans[2]++;
					else ans[1]++; 
				}
				break;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	
	return 0;
} 
