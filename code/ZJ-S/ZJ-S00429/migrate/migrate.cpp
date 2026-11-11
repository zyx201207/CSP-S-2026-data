#include<bits/stdc++.h>//
#define int long long 
using namespace std;
int n,t,c,sum=0;
int a[2000010],s[2000010];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		sum=0;
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			sum+=a[i];
		}sum%=n;
		
		if(sum==0){
			sum++;
			sum%=d;
			cout<<d<<"\n";
		}else{
			sum%d;
			cout<<(sum+1)%d<<"\n";
		}
	}
	return 0;
}//
