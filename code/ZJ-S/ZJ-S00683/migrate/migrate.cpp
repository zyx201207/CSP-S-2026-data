#include <bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d;
long long a[5005];
long long vis1=1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t){
		cin>>n>>d;
		long long sum=0;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
			if(i>=3){
				if((a[i]-a[i-1])!=(a[i-1]-a[i-2])){
					if((a[i]-a[i-1])<=d){
						vis1=0;
					}
				}
			}
		}
		if(n==1||n==2||n==3){
			cout<<0<<"\n";
			t--;
			continue;
		}
		if(vis1==1){
			if((a[3]-a[1])>d){
				cout<<0<<"\n";
			}else if((a[4]-a[1])<=d){
				cout<<0<<"\n";
			}else{
				cout<<n-3<<"\n";
			}
			t--;
			continue;
		}
	}
	return 0;
}
