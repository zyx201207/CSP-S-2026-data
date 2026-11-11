#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
long long x[200005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		scanf("%d%d",&n,&d);
		int sum=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
			for(int j=1;j<i;j++){
				if((x[i]-x[j])%d==1 && (x[i]-x[j])>d){
					sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}