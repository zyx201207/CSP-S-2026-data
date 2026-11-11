#include<bits/stdc++.h>
using namespace std;
int a[2000005],cnt;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	if(c==0){
		while(t--){
			int n,d;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			for(int i=4;i<=n;i+=2){
				int g;
				g++;
				if(a[i]-a[i-2*g+1]<=d&&a[i-2*g+1]-a[i-2*g-1]<=d&&a[i]-a[i-2*g]<=d&&a[i-2*g]-a[i-2*g+1]<=d){
					cnt++;
				}
			}
			cout<<cnt<<"\n";
		}
	}
	return 0;
}

