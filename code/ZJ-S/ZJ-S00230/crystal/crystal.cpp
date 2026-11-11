#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf(" %d",&a[i]);
	}
	if(a[1]-a[0]==a[2]-a[1]){
		long long d=a[1]-a[0];
		long long ans=0;
		for(long long i=1;i<=n;i++){
			long long k=i*(i-1)/2*d;
			if(k<=m)ans=i;
		}
		cout<<ans<<endl;
	}
	else{
		cout<<0;
	}
	return 0;
}
