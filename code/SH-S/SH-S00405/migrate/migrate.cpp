#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+5;
long long x[MAXN];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c>10&&c<13){
		while(t--){
			int n;
			long long d,q;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			sort(x+1,x+n+1);
			q=x[2]-x[1];
			int pt;
			for(pt=4;pt<=n;pt+=2){
				if((pt-1)*q<2*d&&(pt-1)*q>d&&pt/2*q<=d&&(pt/2+1)*q>d)break;
			}
			if(n-pt+1==-1){
				printf("0\n");
				continue;
			}
			cout<<n-pt+1<<endl;
		}
		return 0;
	}
	else if(c>12&&c<15){
		while(t--){
			int n,cnt=0;
			long long d;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			sort(x+1,x+n+1);
			for(int i=2;i<n;i++){
				if(x[i]>=x[n]-d&&x[i]<=x[1]+d)cnt++;
			}
			if(cnt==2)printf("1\n");
			else printf("0\n");
		}
		return 0;
	}
	while(t--){
		int n,ans=0,o;
		long long d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		sort(x+1,x+n+1);
		for(int i=1;i<n;i++){
			long long ma,mi;
			for(o=i+1;o<=n;o++){
				if(x[o]>x[i]+d){
					ma=x[o-2]+d;
					mi=x[o-3]+d;
					break;
				}
			}
			if(x[n]<=mi)break;
			for(int j=o;j<=n;j++){
				if(x[j]>ma)break;
				if(x[j]<=ma&&x[j]>mi)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
