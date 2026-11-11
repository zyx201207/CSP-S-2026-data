#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=200005;
int a[M];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int cnt=0;
		for(int i=1;i<=n;i++){	
			for(int j=i;j<=n;j++){
				int sd=a[j]-a[i];
				int y=sd%d;
				if(j-i>2 && y%2!=0)
					cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}