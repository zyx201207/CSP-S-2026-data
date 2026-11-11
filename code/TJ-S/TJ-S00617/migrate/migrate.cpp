#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t,n,d;
int a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int l=1;l<n;l++){
			int r=n;
			while(l<r){
				if(a[r]-a[l]<=d){
					r--;
					break;
				}
				int anss=0;
				for(int i=l+1;i<r;i++){
					if(((a[i]-a[l])<=d)&&((a[r]-a[i])<=d)){
						anss++;
					}
				}
				if(anss==2){
					ans++;
				}
				r--;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

//0 2 4 2 1 2 3 4 5 2 1 2 3 4 5
//0 2 5 3 -2 -1 0 1 2 6 2 -4 -3 -2 -1 3 6
