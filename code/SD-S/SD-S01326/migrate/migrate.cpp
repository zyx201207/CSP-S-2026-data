#include <iostream>
using namespace std;
using LL=long long;
const int N=1e0+10;

int c,T;
int n,d,a[N]; 

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
	}
	return 0;
}
