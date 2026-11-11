#include<bits/stdc++.h>
using namespace std;
int m,n,a[1000010],t,suma,sumb;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		cout<<n;
		return 0;
	}
	else if(m=2){
		for(int i=1;i<=n;i++){
			if(a[i]==1) suma++;
			if(a[i]==2) sumb++;
		}
		if(suma==n-1 || sumb==n-1){
			cout<<n<<" "<<n;
			return 0;
		}
		for(int i=1;i<=n;i++){
			if(t!=a[i]) t=a[i];
		}
		if(t==1) cout<<n<<" 0";
		else cout<<0<<" "<<n;
	}
	return 0; 
}
