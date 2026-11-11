#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[1000000];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool b=true;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i+1]){
			b=false;
		}
	}
	if(b){
		cout<<n;
	}
	else{
		for(int i=1;i<=n;i++){
			cout<<1<<" ";
		}
	}
	return 0;
}
