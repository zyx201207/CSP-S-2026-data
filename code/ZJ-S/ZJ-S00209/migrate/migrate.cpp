#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d,x[2000005];
		cin>>n>>d;
		int o=0,p=0,m=0;
		for(int i=1;i<=n;++i){
			cin>>x[i];
			if(x[i]%2==0)o++;
			else if(x[i]%3==0)p++;
			else m++;
		}
		if(m>=p)cout<<d-1<<endl;
		else if(o<p+m)cout<<d<<endl;
		else cout<<d-2<<endl;
	}
	return 0;
} 
