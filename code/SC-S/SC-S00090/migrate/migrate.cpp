#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		int n;cin>>n;
		long long d;
		cin>>d;
		long long zs=0;
		long long a[n];
		for(int i=0;i<n;i++){
		    cin>>a[i];
		    zs+=a[i];
		}
		int js=0;
		int p=n-1;
		while(zs>0){
			while(zs%d==0){
			    zs-=a[p];
				p--;
			}
			js+=zs%d;
			zs-=a[p];
			p--;
		}
		cout<<js<<endl;
	}
	return 0;
}
