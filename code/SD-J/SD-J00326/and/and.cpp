#include <bits/stdc++.h>
using namespace std;

int b[20005];



int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int da=0;
	int dada=0;
	
	int a;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		b[i]=a;
		if(a>=da){
			dada=da;
			da=a;
		}
		if(a>=dada&&a!=da){
			dada=a;
		}
	}
	if(m==1){
		cout<<da;
	}
	else if(m==2)cout<<(da&dada);
	else if(m==n){
		int ans;
		ans=b[1];
		for(int i=2;i<=n;i++){
			ans=ans&b[i];
		}
		cout<<ans;
	}
	else{
		int ans;
		ans=b[1];
		for(int i=2;i<=m;i++){
			ans=ans&b[i];
		}
		cout<<ans;
	}
	return 0;
}
