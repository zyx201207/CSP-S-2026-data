#include<bits/stdc++.h>
using namespace std;
long long a[2000005],c,n,m,d,ans,b[2000005];

int main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	cin>>c>>n;
	for(int i=1;i<=n;i++){
		ans=0;
		cin>>m>>d;
		for(int i=1;i<=m;i++){
			cin>>a[i];
			if(a[i]<=d) b[i]=1;
		}
		b[1]=0;
		for(int i=d+1;i<=n;i++){
			if(i%2==0) {
				b[i]=b[i-d]+b[i-d+1];
			}
			else {
				for(int j=1;j<=d;j++){
					b[i]+=b[i-j];
				}
			}
			if(b[i]==2) ans++;
		}
		cout<<ans;
	}
	return 0;
} 
