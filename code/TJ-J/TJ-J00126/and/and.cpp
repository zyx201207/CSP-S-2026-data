#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],f[200010],max1,ans,k;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans=max(max1,a[i]);
	}
	for(int i=1;i<m;i++){
		for(int j=1;j<=n;j++){
			if(j==i) continue;
			if(f[j]==0&&(ans&a[j])>max1){
				max1=(ans&a[j]);
				k=j;		
			}	
		}
		ans=max1;
		f[k]=1;
		max1=0;	
	}
	cout<<ans;
	return 0;
}
