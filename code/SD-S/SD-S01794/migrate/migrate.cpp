#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,T,n,m,a[N],sum=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	for(int t=1;t<=T;t++){
		sum=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			sum+=a[i];
		}
		if(sum==0||abs(sum)==1){
			cout<<abs(sum)<<"\n";
		}else{
			cout<<t<<"\n";
		}
	}
	return 0;
}

