#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	cin>>n>>d;
	for(int p=0;p<t;p++){
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int b=a[1]-a[0];
		if(d/b==2){
			cout<<n-3;
		}else{
			cout<<0;
		}
		
	}
	return 0;
}
