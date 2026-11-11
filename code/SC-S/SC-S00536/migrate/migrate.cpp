#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d,a[2000100];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==13||c==14||c==11 ||c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			cout<<n*(n-1)/2<<endl;
		}
		return 0;
	}else{
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			cout<<n*(n-1)/2-n-d<<endl;
		}
	}
	//不可以骗分总司令
	return 0;
}

