#include<bits/stdc++.h>
using namespace std;
int t,c,n,a[5001],ans,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int z=1;z<=t;z++){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=a[i];j<a[i]+d*2;j++){
				if(j==a[i+2]){
					ans++;
				}
			}
		}
		cout<<ans-1<<endl;
	}
	return 0;
}