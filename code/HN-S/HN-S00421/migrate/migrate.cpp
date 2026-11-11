#include <bits/stdc++.h>
using namespace std;
int c,t,n[100005],d[100005];
int a[1000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i]>>d[i];
		for(int j=1;j<=n[i];j++){
			cin>>a[j];
		}
	}
	for(int i=1;i<=t;i++){
		if(n[i]%d[i]==0){
			cout<<(n[i]-1)/d[i]<<endl;
		}
		else cout<<n[i]/d[i]<<endl;
	}
	return 0;
}

