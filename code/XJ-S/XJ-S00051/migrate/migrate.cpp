#include<bits/stdc++.h>
using namespace std;
long long n,d;
long long a[2000005];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int k=0; k<t; k++){
		cin>>n>>d;
	
		for(int i=0; i<n; i++){
			cin>>a[i];
		}
		
		int cnt=0;
		for(int i=n-1; i>=0; i--){
			a[i]=a[i]-a[i-1];
		}
		
		
		for(int i=3; i<n; i++){
			int c=1;
			for(int j=0; j<=i-3; j++){
				if(a[j+1]+a[j+2]<=d){
					c++;
					if(c>2){
						break;
					}
				}
			}
			cnt+=c==2;
		}
		
		cout<<cnt<<'\n';
	}
	

	return 0;
}
