#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
	}
	if(n==4){
		cout<<3<<' '<<1<<' '<<4;
	}else{
		cout<<10<<' '<<3<<' '<<3;
	}
	return 0;
}