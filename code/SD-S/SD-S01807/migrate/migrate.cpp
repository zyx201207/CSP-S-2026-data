#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,r=1,ans,r1,r2;
long long a[2000005],b[2000005];
int main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}for(int i=0;i<n;i++){
			while(r<=n&&a[r]-a[r-1]<=d){
				r++;
			}r--;
			b[i]=r;
		}
	}for(int i=0;i<n;i++){
		if(b[i]==i){
			continue;
		}r1=b[i-1],r2=b[i-2];
		if(r1==r2){
			continue;
		}while()
		
	}
	return 0;
} 
