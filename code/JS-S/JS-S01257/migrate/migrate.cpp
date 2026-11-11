#include<bits/stdc++.h>

using namespace std;

#define int long long
int c,t,n,d;
int ready[2000010];
signed main(){
	freopen("migrate.in" ,"r",stdin );
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		int lasta=1E18,dif;
		for(int j=1;j<=n;j++){
			int a;
			cin>>a;
			dif=a-lasta;
			lasta=a;
		}
		int much=d/dif;
		int sum=0;
		for(int i=1;i<much;i++){
			ready[i]=pow(2,i-1);
			sum+=ready[i];
		}
		for(int i=much;i<=n;i++){
				ready[i]+=sum;
				sum-=ready[i-much];
			}
		cout<<ready[n]<<endl;
	}
	return  0;
}
