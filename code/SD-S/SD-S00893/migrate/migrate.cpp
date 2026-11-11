#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,a[500005],cnt; 
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if((i-j)%d!=0&&i-j>d)cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}

