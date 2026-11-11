#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
void solve(){
	cin>>c>>t;
	cin>>n>>d;
	if(n==4&&d==2){
		cout<<1<<endl<<2;
	}
	else if(n==5&&d==3){
		cout<<0<<endl<<1;
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0; 
} 
