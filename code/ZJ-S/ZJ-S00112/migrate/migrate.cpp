#include<bits/stdc++.h>
using namespace std;
int c;
long long t,n,d,a[2000001],s=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		s=0;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		for(int j=1;j<n;j++){
			for(int k=j+1;k<=n;k++){
				if(a[j+1]-a[j]<d&&a[j+2]-a[j]<d&&j!=n-1){
					break;
				}
				if((a[k]-a[j])%d<d&&(a[k]-a[j])%d>0&&a[k]-a[j]>d){
					s++;
				}
			}
		}
		cout<<s;
	}
	return 0;
}