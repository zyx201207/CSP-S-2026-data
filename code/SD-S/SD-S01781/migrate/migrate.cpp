#include <bits/stdc++.h>
using namespace std;
long long a[2001000];
struct mzl{
	long long lu;
	long long ci;
};
mzl b[2001000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	for(;t>=1;t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int sum=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n && a[j]-a[j-1]<=d;j++){
				if(a[j]-a[i]<=d){
					b[j].lu=1;
					b[j].ci=1;
				}
				else {
					long long o=3000000000,p=0;
					for(int u=j-1;u>=i && a[j]-a[u]<=d;u--){
						if(b[u].ci<o){
							o=b[u].ci;
							p=b[u].lu;
						}
						else if(b[u].ci==o)p++;
					}
					if(p==2){
						sum++;
					//	cout<<i<<' '<<j<<"\n";
					}
				}
			}
			for(int j=1;j<=n;j++){
				b[j].lu=0;
				b[j].ci=0;
			}
		}
		cout<<sum<<"\n";
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
} 
