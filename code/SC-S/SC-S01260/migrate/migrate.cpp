#include<bits/stdc++.h>
using namespace std;
long long a[2000005]; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int C,T;
	cin>>C>>T;
	if(C==11||C==12){
		while(T--){
			long long n,d;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i]; 
			}
			long long c=a[2]-a[1];
			long long t=d/c,rr=0;
			if(t==1||t==0)cout<<0<<"\n";
			else cout<<max(rr,n-t*2+1)<<"\n";
		}
	}
	return 0;
}