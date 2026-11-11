#include<bits/stdc++.h>
using namespace std;
long long x[1000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
	    int sum=0;
		for(int j=1;j<=n;j++){
			cin>>x[j];
			if(x[j]+2*t-1==x[j+3]){
				sum++;
			}
		}
		
		cout <<sum+1;
	}
	return 0;
}