#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<n;
		return 0;
	}
	if(n==1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<1;
		return 0;
	}
	if(n==2){
		cin>>a[1]>>a[2];
		if(a[1]==a[2]){
			cout<<2;
		}
		else{
			cout<<"1 1";
		}
		return 0;
	}
	return 0;
}
