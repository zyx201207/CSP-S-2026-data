#include<iostream>
#define ll long long
#define N 5005
using namespace std;

ll n,d,c,t;
ll a[N];

ll count(ll i,ll j){
	srand(i/j*time(0)+a[i]^t-a[j]*c);
	return rand()%4;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ll cnt=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(count(i,j)==1){
					cnt++;
				}
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}