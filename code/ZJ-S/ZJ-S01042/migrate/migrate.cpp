#include <bits/stdc++.h>
using namespace std;
int c,T;
int n,d;
int a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		cin>>a[1]>>a[2];
		int p=a[2]-a[1],f=1;
		for(int i=3;i<=n;i++){
			cin>>a[i];
			if(a[i]-a[i-1]!=p){
				f=0;
			}
		}
		if(f==1){
			if(a[n]-a[1]<=d||a[3]-a[1]>=d){
				cout<<0<<endl;
			}else{
				int t=d/p;
				if(2*t>n){
					cout<<0<<endl;
				}else{
					cout<<n-2*t+1<<endl;
				}
			}
		}else if(f==0){
			cout<<0<<endl;
		}
	}
	return 0;
}

