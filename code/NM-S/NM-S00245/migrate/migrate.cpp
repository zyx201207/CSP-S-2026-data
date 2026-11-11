#include<bits/stdc++.h>
using namespace std;

int c,t;

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int s=1;s<=t;s++){
		int n;
		long long d;
		long long x[20005];
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int co=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]>=d){
					co=1;
				}
			}
		}
		cout<<co;
	}
	return 0;
}
