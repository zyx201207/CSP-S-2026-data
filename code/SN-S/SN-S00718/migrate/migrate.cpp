#include<iostream>
#include<cmath>
using namespace std;
lon long arr[1000001];
long long ans=0,d_ans=0;
long long c,t;
long long n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	cin>>n>>d;
	for(int i=1;i<=t;i++){
		for(int j=1;j<=n;j++){
			cin>>arr[i];
		}
	}
	for(int i=1;i<=n;i+=d){
		d_ans++;
		int a=arr[n];
		ceil(a/d);
	}
	for(int i=1;i<=t;i++){
		if(d_ans==2){
			ans++;
		}
		cout<<ans<<endl;;
	}
	return 0;
}
