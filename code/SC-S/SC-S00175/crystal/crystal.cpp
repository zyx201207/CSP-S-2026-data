#include <bits/stdc++.h>
using namespace std;
long long k,n,m,a[500025],c[500025],i,s=0,r,used[500025];
void dfs(long long z,long long h){
	if(z>=k){
		cout<<z<<" "<<h<<endl;
		if((h+m)/k*k==h+m&&(h+m)/k>=a[n]) s=1;
		
	}
	for(r=n;r>=1;r--){
		if(s==1) return;
		if(used[r]==0&&z<5){
			dfs(++z,h+=a[r]);
			used[r]=1;
		}
	} 
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long f=0;
	for(i=1;i<=n;i++){
		cin>>a[i];
		c[i]=a[i];
	}
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++){
		if(a[i]!=i) f=1;
	}
	if(f==0){
		if(m>=n*(n-1)/2){
			cout<<n;
			return 0;
		}
		else{
			for(i=1;i<=n;i++){
				if(m>=i*(i+1)/2&&m<(i+1)*(i+2)/2){
					cout<<i+1;
					return 0;
				}
			}
		}
	}
	else{
		for(k=n;k>=1;k--){
			dfs(0,0);
			if(s==1){
				cout<<k;
				return 0;
			}
			else s=0;
		}
	}
	return 0;
}