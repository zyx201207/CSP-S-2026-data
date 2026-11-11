#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000010],x;
bool f;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=0;i<n;++i) cin>>a[i];
		x=a[1]-a[0],f=0;
		for(int i=2;i<n;++i) if(a[i]-a[i-1]!=x){
			f=1;
			break;
		}
		if(f){
			if(n%2==0 && d%2==0) cout<<1;
			else if(n%2==1 && d%2==1) cout<<0;
			else cout<<n/3+1;
		}else{
			if(x>d) cout<<0;
			else cout<<n-3;
		}
		cout<<'\n';
	} 
	return 0;
} 
