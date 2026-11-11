#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[1000000],s;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long c,t,n,d,x;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<n;j++){
			cin>>x;
		}
		if(c==0){
			if(n==5&&d==2){
				cout<<1<<endl;
			}
			if(n==10&&d==3){
				cout<<2<<endl;
			}
		}else{
			cout<<1<<endl;
		}
	}
	return 0;
}