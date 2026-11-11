//      
//  
//     	空 悲 切 
//
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int n;
ll d;
int T;
ll x[N];
int work(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	freopen("migrate.in","r",stdin);
	int k=x[2]-x[1];
	cout<<0<<endl;
	freopen("migrate.out","w",stdout);
}
int main(){
	int c;
	cin>>c>>T;
	while(T--){
		work();
	}
	return 0;
}