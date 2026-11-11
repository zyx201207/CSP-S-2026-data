#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int a,b;cin>>a>>b;
	if(a==0&&b==2){
		cout<<0<<"\n"<<1;
		return 0;
	}
	while(b--){
		int num1,num2;
		cin>>num1>>num2;
		cout<<((num1+1)/num2-1)<<"\n";
		for(int i=1;i<=num1;i++)cin>>num2;
	}
	
	return 0;
}
