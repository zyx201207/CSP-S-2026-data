#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
typedef long long ll;
long long c,t;
long long n,d;
long long a[N];
ll pd(ll i,ll j,ll g){
//	cout<<i<<" "<<j<<" "<<g<<" ";
//	cout<<i<<" ";
	if(i==j){
		if(g==0) return true;
		else return false;
	}
	ll res=0;
	for(int k=i+1;k<=j;k++){
		if(a[k]-a[i]<=d){
			res+=pd(k,j,g-1);
//			cout<<endl;
		}
		else break;
	}
	
	return res;
}
ll ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	int bj;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i =1;i<=n;i++) cin>>a[i];
		for(int i =1;i<=n;i++){
			for(int j =i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					continue;;
				}
				for(int g=2;g<=j-i;g++){
					bj=pd(i,j,g);
					if(bj==2){
						ans++;break;
					}
					else{
						if(bj!=0){
							break;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
