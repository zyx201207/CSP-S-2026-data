#include<bits/stdc++.h>
using namespace std;
int c,t;
int x[2002000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while (t--){
		int n,d;
		cin>>n>>d;
		bool f=true;
		int q=0;
		for (int i=1;i<=n;i++){
			cin>>x[i];
			if (i>2){
				if (q!=x[i]-x[i-1]){
					f=false;
				}
			}
			if (i!=1) q=x[i]-x[i-1];
		}
		if (f){
			d/=q;
			int len=d*2;
			cout<<n-len+1<<"\n";
		}
		else{
			cout<<1<<"\n";
		}
	}
	return 0;
}

