#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,l,num;
long long a[2000005];
long long b[2000005];
long long f[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(f,0,sizeof(f));
		num=0;
		cin>>n>>d;
		if(n<4){
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			l = d;
			int j = i;
			while(l&&j<n){
				l -= a[j+1]-a[j];
				j++;
			}
			if(j!=b[i-1]){
				b[i]=j;
			}
		}
//		for(int i=1;i<=n;i++){
//			cout<<b[i]<<" ";
//		}
		for(int i=n-3;i>=1;i--){
			if(b[b[i]-1]-1==b[i]){
				num++;
			}
		}
		cout<<num<<endl;
	}
	return 0;
}
