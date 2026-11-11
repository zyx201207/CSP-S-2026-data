#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t,n,d,a[2000005];
ll solve1(int k){
	if(d<=k) return 0;
	int l=d/k;
	return n-l*2+1;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int k=a[2]-a[1];
		bool f1=1;
		for(int i=3;i<=n;i++){
			if(a[i]-a[i-1]!=k) f1=0;
			k=a[i]-a[i-1];
		}
		if(f1){
			cout<<solve1(k)<<endl;
			continue;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
}
