#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+10;
ll c,t,n,d,pa;
ll a[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int l=1,r=4;
		bool f=false;
		pa=0;
		while(l<=n&&r<=n){
			while(a[r]-a[l]<=d){
				r++;
				if(r-l>3) l++;
				if(r>n){
					f=true;
					break;
				}
			}
			if(f) break;
			if(r-l==3&&a[r]-a[l+1]<=d&&a[l+2]-a[l]<=d){
				pa++;
				r++;
			}else{
				l++;
			}
			while(r-l>3) l++;
			while(r-l<3) r++;
		}
		cout<<pa<<endl;
	}
	
	return 0;
}