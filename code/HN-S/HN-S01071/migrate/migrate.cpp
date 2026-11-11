#include<bits/stdc++.h>
using namespace std;
int c,t;
const int h=1e7*2+5;
long long n,d;
long long a[h];
int main(){
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
cin>>c>>t;
for(int i=1;i<=t;i++){
	cin>>n>>d;
	for(int j=1;j<=n;j++){
		cin>>a[j];
	}
	if(d<a[2]-a[1]||n<4){
		cout<<"0"<<endl;
	}
	else{
		long long allans=n/(d/(a[2]-a[1])-1);
		cout<<allans<<endl;
	}
}
fclose(stdin);
fclose(stdout);
	return 0;
}
