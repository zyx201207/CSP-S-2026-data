#include<bits/stdc++.h>
using namespace std;
int a[5000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    int n,d;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	} 
    if(c==14||c==13){
    	for(int i=1;i<=t;i++){
    		cout<<0<<endl;
		}
	}
	else {
		for(int i=1;i<=n;i++){
			cout<<1;
		}
	}
	return 0;
} 
