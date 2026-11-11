#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,n,d,a[21000],s[11000];
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		for(int j=1;j<=n;j++){
			for(int q=j+3;q<=n;q++){
				if((a[q]-a[j])%d!=0&&a[q]-a[j]>d){
					s[i]++;
				}
			}
		}
	}
	for(int i=1;i<=t;i++){
		cout<<s[i]<<endl;
	}
	return 0;
}
