#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[10009];
int main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){cin>>a[i];}
		int aa=a[2];
		int ad=aa/d;
		int dd=(n-1)/ad;
	//if(dd*ad==n-1)dd=-1;
		int sh=(dd-1)*dd;
		cout<<sh-5<<endl;
	}
	return 0;
}
