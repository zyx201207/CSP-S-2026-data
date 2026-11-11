#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,p,ans,a[10000005],b[1000005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=p;i++){
		for(int j=1;j<=m;j++){
			cin>>a[j];
			cin>>b[j];
			ans+=a[j];
		}
		ans+=b[1]+b[m];
		cout<<ans;
	}
	return 0;
}
