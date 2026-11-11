#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,crys[500005],ans;
//crystalized--Camellia
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>crys[i];
	}
	sort(crys+1,crys+n+1);
	long long l=1,r=1,tempp=0;
	while(r<=n){
		r++;
		tempp+=(r-l)*(crys[r]-crys[r-1]);
		while(tempp>m){
			tempp-=(crys[r]-crys[l]);
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
