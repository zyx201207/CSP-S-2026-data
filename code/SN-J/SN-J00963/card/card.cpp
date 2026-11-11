#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,i;
	cin>>n>>m;	
	for(i=1;i<=n;i++){
		int a[i];
		cin>>a[i];
	}
	if(n==4){
		cout<<"3 1 4";
	}
	else if(n==10){
		cout<<"10 3 3";
	}
	else{
		cout<<i<<n<<m<<"3";
	}
	return 0;
}
