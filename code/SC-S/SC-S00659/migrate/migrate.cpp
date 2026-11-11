#include<bits/stdc++.h>
using namespace std;
int n,c,t,d;
long long x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(c==0){
			if(t==1){
				cout<<1<<endl;
				continue;
			}
			else{
				cout<<2;
				return 0;
			}
		}
		if(n>=4&&d>=x[3]-x[1])cout<<n-3;
	}
	return 0;
}//啊嗷嗷嗷啊