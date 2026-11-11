#include<bits/stdc++.h>
using namespace std;
int c,t,s=0;
int n;
long long d;
long long a[2*1000000+1];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(j-i+1>=4&&a[j]-a[i]>d){
					int k=0;
					for(int o=i;o<j;o++){
						if(a[o+1]-a[o]>t){
							k=1;
						}
					}
					if(k==0){
						s++;
					}
				}
			}
		}
		cout<<s/2;
	}
	return 0;
}
