#include<bits/stdc++.h>
using namespace std;
long long n,m,a[2000008],b[2000008],sum,maxx,q,t,T;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t>>T;
	while(T--){
		sum=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			b[i]=0;
		}
		sort(a+1,a+n+1);
		b[1]=1;
		for(int i=1;i<=n;i++){
			int t=upper_bound(a+1,a+n+1,a[i]+m)-a-1;
			for(int j=i+1;j<=t;j++){
				b[j]++;
			}
		}
		for(int i=1;i<=n;i++){
			if(b[i]==2)sum++;
//			cout<<b[i];
		}
		cout<<sum-1<<"\n";
	}
	
	fclose(stdin);
	fclose(stdin);
	return 0;
}