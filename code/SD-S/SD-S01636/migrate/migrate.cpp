#include<bits\stdc++.h> 
using namespace std;
int a[100000];
long long ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		ans=0;
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				if(a[j]-a[j-1]<=d&&a[j]-a[j-2]<=d&&a[j-2]-a[i]<=d&&a[j-1]-a[i]<=d&&a[j]-a[i]>d){
					//cout<<a[j-2]<<' '<<a[i]<<' '<<a[j-1]/*-a[i]*/<<' ';
					//cout<<i<<' '<<j<<endl;
					j++;ans++;
					while(j<=n&&a[j]-a[j-1]<=d&&a[j]-a[j-2]>d){
						ans++;
						j++;
						cout<<i<<' '<<j<<endl;
					}
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
