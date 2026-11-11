#include<bits/stdc++.h>
using namespace std;

long long a[10000],c,n,d,t,k;

int main (){
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]==a[j+1]-a[i+1]) k++;
			}
		}
		cout<<k/2;
	}
	
	return 0;
}
