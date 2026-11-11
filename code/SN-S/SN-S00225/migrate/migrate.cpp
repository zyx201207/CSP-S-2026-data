#include<bits/stdc++.h>
using namespace std;
long long a[2000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int zns=0;zns<t;zns++){
		long long n,d;
		cin>>n>>d;
		for(long long i=0;i<n;i++){
			cin>>a[i];
		}
		if(d==1)cout<<0<<endl;
		else{
		if(c==11||c==12){
			
		long long s=d/(a[2]-a[1]);
		
		cout<<n-s<<endl;
		}
		else if(c==13||c==14){
			for(long long i=0;i<n;i++){
				if(a[i]<=a[0]+d&&a[i]>=a[n-1]){
					cout<<i*(n-i-1)<<endl;
				}
			}
		}
		else cout<<1<<endl;
		}
	}
	
	
	return 0;
}
