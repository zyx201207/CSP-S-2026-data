#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
long long c,T,m,n,a[500005],b[500005],sum,ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>T;
	while(T--){
		sum=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i-1]+m<a[i]) {
				n=i-1;
				break;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]+2*m-1<=a[n]){
				sum++;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
} 
