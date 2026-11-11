#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+7;
ll c,t,cnt=0;
ll n,d,x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		n+=1;
	while(n--){
		for(int k=1;k<=n;k++){
			ll dis=x[n]-x[k];
			if(dis%d==0){
				continue;
			}else if(dis<d){
				continue;
			}else if(dis%d==1&&dis>d&&n-k==3){
				cnt++;
			}
		}
	}
		cout<<cnt<<endl;
		cnt=0;
	}
	return 0;
}
