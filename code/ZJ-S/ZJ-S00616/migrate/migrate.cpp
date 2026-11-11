#include <bits/stdc++.h>
using namespace std;
long long c,t;
long long a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long n,d,sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n<=3){
			cout<<"0\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			if(a[n]-a[i]<=d) break;
			for(int j=i;j<=n;j++){
				if(a[j]-a[i]<=d) continue;
				if(a[j]-a[i]>=2*d) break;
				int cnt=0;
				for(int k=i+1;k<=j-1;k++){
					if(a[k]-a[i]<=d && a[j]-a[k]<=d){
						cnt++;
					}
					if(cnt>2) break;	
				}
				if(cnt==2) sum++;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}