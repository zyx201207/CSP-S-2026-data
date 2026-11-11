#include<bits/stdc++.h>
using namespace std;
int z(int a){
	if(a<0) a=0-a;
	return a;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	for(int pq=0;pq<t;pq++){
		int n,d;
		cin>>n>>d;
		int a[n+2];
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==13||c==14){
			bool ok=1;
			for(int i=1;i<=n&&ok;i++){
				if(z(a[1]-a[i])<=d&&z(a[n]-a[i])<=d){
					for(int j=i+1;j<=n&&ok;j++){
						int be=(i*i-i)/2;
						int k=n-i;
						int fu=(k*k-k)/2;
						int sum=be+fu;
						cout<<sum;
						ok=0;
					}
				}
			}
		}	
		else{
			cout<<0;
		}
	}
	return 0;
}