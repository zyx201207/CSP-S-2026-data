#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n,d;
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		int x[50001];
		for(int j=1;j<=n;j++){
			cin>>x[i];
		}
		int cnt=0;
		int f=x[2]-x[1];
		for(int h=1;h<=n;h++){
			for(int g=h;g<=n;g++){
				if(d>2*f&&x[g]-x[h]>=2*f&&d<x[g]-x[h]){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
return 0;
}
